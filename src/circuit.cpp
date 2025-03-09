/*
** EPITECH PROJECT, 2025
** Circuit.cpp
** File description:
** Circuit for NanoTekSpice
*/

#include "Circuit.hpp"
#include <iostream>
#include "ComponentFactory.hpp"
#include <map>

namespace nts {
    void Circuit::loadFile(const std::string& filename)
    {
        parser.parseFile(filename);
        ComponentFactory factory;

        for (const auto& chipset : parser.getChipsets()) {
            std::unique_ptr<IComponent> component = factory.createComponent(chipset.type, chipset.name);
            std::shared_ptr<IComponent> sharedComponent = std::move(component);
            components.push_back(sharedComponent);

            if (chipset.type == "input" || chipset.type == "clock") {
                inputs.push_back(sharedComponent);
            }
            if (chipset.type == "output") {
                outputs.push_back(sharedComponent);
            }
        }

        std::map<std::string, std::shared_ptr<IComponent>> componentMap;
        for (const auto& component : components)
            componentMap[component->getName()] = component;

        for (const auto& link : parser.getLinks()) {
            auto comp1 = componentMap.find(link.component1);
            auto comp2 = componentMap.find(link.component2);
            
            if (comp1 != componentMap.end() && comp2 != componentMap.end()) {
                comp1->second->setLink(link.pin1, *(comp2->second), link.pin2);
                comp2->second->setLink(link.pin2, *(comp1->second), link.pin1);
            }
        }
    }

    void Circuit::displayContent() const
    {
        std::cout << "Chipsets:" << std::endl;
        for (const auto& chipset : parser.getChipsets()) {
            std::cout << "  Type: " << chipset.type 
                      << ", Name: " << chipset.name << std::endl;
        }

        std::cout << "\nLinks:" << std::endl;
        for (const auto& link : parser.getLinks()) {
            std::cout << "  " << link.component1 << ":" << link.pin1 
                      << " -> " << link.component2 << ":" << link.pin2 << std::endl;
        }
    }

    const std::vector<std::shared_ptr<IComponent>>& Circuit::getInputs() const
    {
        return inputs;
    }

    const std::vector<std::shared_ptr<IComponent>>& Circuit::getOutputs() const
    {
        return outputs;
    }

    void Circuit::simulate()
    {
        for (auto& component : components) {
            if (component->getType() != "output") {
                component->simulate(0);
            }
        }

        for (auto& component : components) {
            if (component->getType() == "output") {
                component->simulate(0);
            }
        }
    }

    bool Circuit::setInputValue(const std::string& name, nts::Tristate value) {
        for (auto& input : inputs) {
            if (input->getName() == name) {
                input->setState(value);
                return true;
            }
        }
        return false;
    }
}

/*
** EPITECH PROJECT, 2025
** OutputComponent.hpp
** File description:
** Outpout for NanoTekSpice
*/

#ifndef OUTPUT_COMPONENT_HPP
#define OUTPUT_COMPONENT_HPP

#include "IComponent.hpp"
#include <memory>

namespace nts {
    class OutputComponent : public IComponent {
    public:
        OutputComponent(const std::string& name) : name(name), state(Tristate::Undefined), linkedComponent(nullptr), linkedPin(0) {}

        void simulate(std::size_t) override {
            if (linkedComponent) {
                state = linkedComponent->compute(linkedPin);
            }
        }

       Tristate compute(std::size_t) const override {
            if (linkedComponent) {
                return linkedComponent->compute(linkedPin);
            }
            return state;
}

        void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override {
            if (pin == 1) {
                linkedComponent = &other;
                linkedPin = otherPin;
            }
        }

        std::string getName() const override { return name; }
        void setState(Tristate newState) override { state = newState; }
        std::string getType() const override { return "output"; }

    private:
        std::string name;
        Tristate state;
        IComponent* linkedComponent;
        std::size_t linkedPin;
    };
}

#endif // OUTPUT_COMPONENT_HPP
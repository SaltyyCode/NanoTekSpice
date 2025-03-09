/*
** EPITECH PROJECT, 2025
** 4069.cpp
** File description:
** 4069 gate for NanoTekSpice
*/

#include "Gates_Components/4069.hpp"

namespace nts {
    Component4069::Component4069(const std::string& name) 
        : AComponent(name)
    {
        gates[0] = std::make_shared<NotComponent>(name + "_NOT1");
        gates[1] = std::make_shared<NotComponent>(name + "_NOT2");
        gates[2] = std::make_shared<NotComponent>(name + "_NOT3");
        gates[3] = std::make_shared<NotComponent>(name + "_NOT4");
        gates[4] = std::make_shared<NotComponent>(name + "_NOT5");
        gates[5] = std::make_shared<NotComponent>(name + "_NOT6");
    }

    Component4069::~Component4069() {}

    void Component4069::simulate(std::size_t tick) {
        (void)tick;
        for (auto& gate : gates) {
            gate->simulate(tick);
        }
    }

    Tristate Component4069::compute(std::size_t pin) const {
        switch (pin) {
            case 2: return gates[0]->compute(2);
            case 4: return gates[1]->compute(2);
            case 6: return gates[2]->compute(2);
            case 8: return gates[3]->compute(2);
            case 10: return gates[4]->compute(2);
            case 12: return gates[5]->compute(2);
            default: return Tristate::Undefined;
        }
    }

    void Component4069::setLink(std::size_t pin, IComponent& other, std::size_t otherPin) {
        switch (pin) {
            case 1: 
                gates[0]->setLink(1, other, otherPin);
                break;
            case 3: 
                gates[1]->setLink(1, other, otherPin);
                break;
            case 5: 
                gates[2]->setLink(1, other, otherPin);
                break;
            case 9: 
                gates[3]->setLink(1, other, otherPin);
                break;
            case 11: 
                gates[4]->setLink(1, other, otherPin);
                break;
            case 13: 
                gates[5]->setLink(1, other, otherPin);
                break;
        }
    }

    std::string Component4069::getType() const {
        return "4069";
    }
}

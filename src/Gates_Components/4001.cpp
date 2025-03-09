/*
** EPITECH PROJECT, 2025
** 4001.cpp
** File description:
** 4001 gate for NanoTekSpice
*/
#include "Gates_Components/4001.hpp"

namespace nts {
    Component4001::Component4001(const std::string& name) 
        : AComponent(name)
    {
        gates[0] = std::make_shared<NorComponent>(name + "_NOR1");
        gates[1] = std::make_shared<NorComponent>(name + "_NOR2");
        gates[2] = std::make_shared<NorComponent>(name + "_NOR3");
        gates[3] = std::make_shared<NorComponent>(name + "_NOR4");
    }

    Component4001::~Component4001() {}


    void Component4001::simulate(std::size_t tick) 
    {
        (void)tick;
        for (auto& gate : gates) {
            gate->simulate(tick);
        }
    }

    Tristate Component4001::compute(std::size_t pin) const 
    {
        switch (pin) {
            case 3: return gates[0]->compute(3);
            case 4: return gates[1]->compute(3);
            case 10: return gates[2]->compute(3);
            case 11: return gates[3]->compute(3);
            default: return Tristate::Undefined;
        }
    }

    void Component4001::setLink(std::size_t pin, IComponent& other, std::size_t otherPin) 
    {
        switch (pin) {
            case 1: case 2:
                gates[0]->setLink(pin, other, otherPin);
                break;
            case 5: case 6:
                gates[1]->setLink(pin == 5 ? 1 : 2, other, otherPin);
                break;
            case 8: case 9:
                gates[2]->setLink(pin == 8 ? 1 : 2, other, otherPin);
                break;
            case 12: case 13:
                gates[3]->setLink(pin == 12 ? 1 : 2, other, otherPin);
                break;
        }
    }

    std::string Component4001::getType() const {
        return "4001";
    }
}

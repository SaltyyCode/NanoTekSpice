/*
** EPITECH PROJECT, 2025
** NandComponent.cpp
** File description:
** Nand gate for NanoTekSpice
*/

#include "Elementary_Components/NandComponent.hpp"

namespace nts {
    NandComponent::NandComponent(const std::string& name) 
        : AComponent(name) {}

    void NandComponent::simulate(std::size_t tick)
    {
        (void)tick;
        state = compute(3);
    }

    Tristate NandComponent::compute(std::size_t pin) const
    {
        if (pin != 3) return Tristate::Undefined;

        auto it1 = inputLinks.find(1);
        auto it2 = inputLinks.find(2);
        if (it1 == inputLinks.end() || it2 == inputLinks.end())
            return Tristate::Undefined;

        Tristate input1 = it1->second.first->compute(it1->second.second);
        Tristate input2 = it2->second.first->compute(it2->second.second);

        if (input1 == Tristate::False || input2 == Tristate::False)
            return Tristate::True;
        if (input1 == Tristate::Undefined || input2 == Tristate::Undefined)
            return Tristate::Undefined;
        return Tristate::False;
    }

    std::string NandComponent::getType() const
    {
        return "nand";
    }
}

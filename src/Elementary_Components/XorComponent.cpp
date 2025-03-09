/*
** EPITECH PROJECT, 2025
** Xor.cpp
** File description:
** Xor for NanoTekSpice
*/

#include "Elementary_Components/XorComponent.hpp"

namespace nts {
    XorComponent::XorComponent(const std::string& name) 
        : AComponent(name) {}

    void XorComponent::simulate(std::size_t tick) {
        (void)tick;
        state = compute(3);
    }

   Tristate XorComponent::compute(std::size_t pin) const
    {
        if (pin != 3) return Tristate::Undefined;

        auto it1 = inputLinks.find(1);
        auto it2 = inputLinks.find(2);
        if (it1 == inputLinks.end() || it2 == inputLinks.end())
            return Tristate::Undefined;

        Tristate input1 = it1->second.first->compute(it1->second.second);
        Tristate input2 = it2->second.first->compute(it2->second.second);

    
        if (input1 == Tristate::Undefined || input2 == Tristate::Undefined)
            return Tristate::Undefined;

        return (input1 == input2) ? Tristate::False : Tristate::True;
    }


    std::string XorComponent::getType() const
    {
        return "xor";
    }
}
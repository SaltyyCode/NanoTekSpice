/*
** EPITECH PROJECT, 2025
** Or.cpp
** File description:
** Or gate for NanoTekSpice
*/

#include "Elementary_Components/OrComponent.hpp"

namespace nts {
    OrComponent::OrComponent(const std::string& name) 
        : AComponent(name) {}

    void OrComponent::simulate(std::size_t tick)
    {
        (void)tick;
        state = compute(3);
    }

    Tristate OrComponent::compute(std::size_t pin) const
    {
        if (pin != 3) return Tristate::Undefined;

        auto it1 = inputLinks.find(1);
        auto it2 = inputLinks.find(2);
        if (it1 == inputLinks.end() || it2 == inputLinks.end())
            return Tristate::Undefined;

        Tristate input1 = it1->second.first->compute(it1->second.second);
        Tristate input2 = it2->second.first->compute(it2->second.second);

        if (input1 == Tristate::True || input2 == Tristate::True)
            return Tristate::True;
        if (input1 == Tristate::Undefined || input2 == Tristate::Undefined)
            return Tristate::Undefined;
        return Tristate::False;
    }

    std::string OrComponent::getType() const
    {
        return "or";
    }
}

/*
** EPITECH PROJECT, 2025
** Not.cpp
** File description:
** Not gate for NanoTekSpice
*/

#include "Elementary_Components/NotComponent.hpp"

namespace nts {
    NotComponent::NotComponent(const std::string& name) 
        : AComponent(name) {}

    void NotComponent::simulate(std::size_t tick)
    {
        (void)tick;
        state = compute(2);
    }

    Tristate NotComponent::compute(std::size_t pin) const
    {
        if (pin != 2) return Tristate::Undefined;

        auto it = inputLinks.find(1);
        if (it == inputLinks.end())
            return Tristate::Undefined;

        Tristate input = it->second.first->compute(it->second.second);
        if (input == Tristate::True)
            return Tristate::False;
        if (input == Tristate::False)
            return Tristate::True;
        return Tristate::Undefined;
    }

    std::string NotComponent::getType() const {
        return "not";
    }
}

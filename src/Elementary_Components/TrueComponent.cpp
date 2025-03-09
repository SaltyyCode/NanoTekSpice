/*
** EPITECH PROJECT, 2025
** True.cpp
** File description:
** True for NanoTekSpice
*/

#include "Elementary_Components/TrueComponent.hpp"

namespace nts {
    TrueComponent::TrueComponent(const std::string& name) 
        : AComponent(name) 
    {
        state = Tristate::True;
    }

    void TrueComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }

    Tristate TrueComponent::compute(std::size_t pin) const
    {
        (void)pin;
        return Tristate::True;
    }

    std::string TrueComponent::getType() const
    {
        return "true";
    }
}

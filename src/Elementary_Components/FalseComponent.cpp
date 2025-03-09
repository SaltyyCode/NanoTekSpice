/*
** EPITECH PROJECT, 2025
** False.cpp
** File description:
** False for NanoTekSpice
*/


#include "Elementary_Components/FalseComponent.hpp"

namespace nts {
    FalseComponent::FalseComponent(const std::string& name) 
        : AComponent(name) 
    {
        state = Tristate::False;
    }

    void FalseComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }

    Tristate FalseComponent::compute(std::size_t pin) const
    {
        (void)pin;
        return Tristate::False;
    }

    std::string FalseComponent::getType() const
    {
        return "false";
    }
}

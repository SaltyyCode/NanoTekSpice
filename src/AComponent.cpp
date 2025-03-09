/*
** EPITECH PROJECT, 2025
** AComponent.cpp
** File description:
** Abstract class for NanoTekSpice
*/

#include "AComponent.hpp"

namespace nts {
    AComponent::AComponent(const std::string& name)
        : name(name), state(Tristate::Undefined) {}

    void AComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }

    void AComponent::setLink(std::size_t pin, IComponent& other, std::size_t otherPin)
    {
        inputLinks[pin] = std::make_pair(&other, otherPin);
    }

    std::string AComponent::getName() const
    {
        return name;
    }

    void AComponent::setState(Tristate newState)
    {
        state = newState;
    }
}

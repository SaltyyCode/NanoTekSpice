/*
** EPITECH PROJECT, 2025
** ClockComponent.cpp
** File description:
** File for clock component
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(const std::string& name)
    : name(name), state(Tristate::Undefined), manuallySet(false) {}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
      
    if (manuallySet)
    {
        manuallySet = false;
        return;
    }
    
    if (state == Tristate::True)
        state = Tristate::False;
    else if (state == Tristate::False)
        state = Tristate::True;
}

nts::Tristate nts::ClockComponent::compute(std::size_t) const
{
    return state;
}

void nts::ClockComponent::setLink(std::size_t, IComponent&, std::size_t)
{
  
}

std::string nts::ClockComponent::getName() const 
{
    return name;
}

void nts::ClockComponent::setState(Tristate newState) 
{
    state = newState;
    manuallySet = true;
}

std::string nts::ClockComponent::getType() const 
{
    return "clock";
}
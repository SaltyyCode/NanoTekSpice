/*
** EPITECH PROJECT, 2025
** Nor.cpp
** File description:
** Nor gate fNor NanoTekSpice
*/

#include "Elementary_Components/NorComponent.hpp"

namespace nts {
    NorComponent::NorComponent(const std::string& name) 
        : AComponent(name) {}

    void NorComponent::simulate(std::size_t tick)
    {
        (void)tick;
        state = compute(3);
    }

    Tristate NorComponent::compute(std::size_t pin) const
    {
        if (pin != 3)
            return Tristate::Undefined;

        static std::set<const IComponent*> computingComponents;
        
        if (computingComponents.find(this) != computingComponents.end()) {
            return state;
        }
        
        computingComponents.insert(this);
    
        auto it1 = inputLinks.find(1);
        auto it2 = inputLinks.find(2);
        
        Tristate result = Tristate::Undefined;
        
        if (it1 != inputLinks.end() && it2 != inputLinks.end()) {
            Tristate input1 = it1->second.first->compute(it1->second.second);
            Tristate input2 = it2->second.first->compute(it2->second.second);

            if (input1 == Tristate::True || input2 == Tristate::True)
                result = Tristate::False;
            else if (input1 == Tristate::Undefined || input2 == Tristate::Undefined)
                result = Tristate::Undefined;
            else
                result = Tristate::True;
        }

        computingComponents.erase(this);
        
        return result;
    }


    std::string NorComponent::getType() const
    {
        return "nor";
    }
}

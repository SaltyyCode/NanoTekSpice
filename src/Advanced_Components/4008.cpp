/**
** EPITECH PROJECT, 2025
** 4008.cpp
** File description:
** 4008 gate (4 bits adder) for NanoTekSpice
*/

#include "Advanced_Components/4008.hpp"

namespace nts {
    Component4008::Component4008(const std::string& name)
        : AComponent(name)
    {
        for (auto& result : results) {
            result = Tristate::Undefined;
        }
    }

    Component4008::~Component4008() {}

    void Component4008::simulate(std::size_t tick)
    {
        (void)tick;
        
        auto getValue = [this](std::size_t pin) -> Tristate {
            auto it = inputLinks.find(pin);
            if (it == inputLinks.end() || !it->second.first)
                return Tristate::Undefined;
            return it->second.first->compute(it->second.second);
        };
        Tristate a1 = getValue(7);
        Tristate b1 = getValue(6);
        Tristate a2 = getValue(5);
        Tristate b2 = getValue(4);
        Tristate a3 = getValue(3);
        Tristate b3 = getValue(2);
        Tristate a4 = getValue(1);
        Tristate b4 = getValue(15);
        Tristate cin = getValue(9);
        auto fullAdder = [](Tristate a, Tristate b, Tristate cin) -> std::pair<Tristate, Tristate> {
            if (a == Tristate::Undefined || b == Tristate::Undefined || cin == Tristate::Undefined)
                return {Tristate::Undefined, Tristate::Undefined};

            bool aVal = (a == Tristate::True);
            bool bVal = (b == Tristate::True);
            bool cinVal = (cin == Tristate::True);
            bool sum = aVal ^ bVal ^ cinVal;
            bool cout = (aVal && bVal) || (aVal && cinVal) || (bVal && cinVal);
            return {sum ? Tristate::True : Tristate::False, 
                    cout ? Tristate::True : Tristate::False};
        };

        auto [sum1, carry1] = fullAdder(a1, b1, cin);
        auto [sum2, carry2] = fullAdder(a2, b2, carry1);
        auto [sum3, carry3] = fullAdder(a3, b3, carry2);
        auto [sum4, cout] = fullAdder(a4, b4, carry3);
        results[0] = sum1;
        results[1] = sum2;
        results[2] = sum3;
        results[3] = sum4;
        results[4] = cout;
    }

    Tristate Component4008::compute(std::size_t pin) const
    {
        switch (pin) {
            case 10: return results[0];
            case 11: return results[1];
            case 12: return results[2];
            case 13: return results[3];
            case 14: return results[4];
            default: return Tristate::Undefined;
        }
    }

    void Component4008::setLink(std::size_t pin, IComponent& other, std::size_t otherPin)
    {
        AComponent::setLink(pin, other, otherPin);
    }

    std::string Component4008::getType() const
    {
        return "4008";
    }
}
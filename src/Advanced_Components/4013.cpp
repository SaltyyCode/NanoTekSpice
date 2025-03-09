/**
** EPITECH PROJECT, 2025
** 4013.cpp
** File description:
** 4013 gate (Dual D-Type Flip-Flop) for NanoTekSpice
*/

#include "Advanced_Components/4013.hpp"

namespace nts {
    Component4013::Component4013(const std::string& name)
        : AComponent(name), q1(Tristate::Undefined), q1Bar(Tristate::Undefined),
          q2(Tristate::Undefined), q2Bar(Tristate::Undefined),
          lastClock1(Tristate::Undefined), lastClock2(Tristate::Undefined)
    {
    }

    Component4013::~Component4013() {}

    void Component4013::simulate(std::size_t tick) {
        (void)tick;

        auto getValue = [this](std::size_t pin) -> Tristate {
            auto it = inputLinks.find(pin);
            if (it == inputLinks.end() || !it->second.first)
                return Tristate::Undefined;
            return it->second.first->compute(it->second.second);
        };

        Tristate data1 = getValue(5);
        Tristate set1 = getValue(6);
        Tristate reset1 = getValue(4);
        Tristate clock1 = getValue(3);
        Tristate data2 = getValue(9);
        Tristate set2 = getValue(8);
        Tristate reset2 = getValue(10);
        Tristate clock2 = getValue(11);

        if (reset1 == Tristate::True) {
            q1 = Tristate::False;
            q1Bar = Tristate::True;
        } else if (set1 == Tristate::True) {
            q1 = Tristate::True;
            q1Bar = Tristate::False;
        } else if (clock1 == Tristate::True && lastClock1 == Tristate::False) {
            if (data1 != Tristate::Undefined) {
                q1 = data1;
                q1Bar = (data1 == Tristate::True) ? Tristate::False : Tristate::True;
            }
        }
        if (reset2 == Tristate::True) {
            q2 = Tristate::False;
            q2Bar = Tristate::True;
        } else if (set2 == Tristate::True) {
            q2 = Tristate::True;
            q2Bar = Tristate::False;
        } else if (clock2 == Tristate::True && lastClock2 == Tristate::False) {
            if (data2 != Tristate::Undefined) {
                q2 = data2;
                q2Bar = (data2 == Tristate::True) ? Tristate::False : Tristate::True;
            }
        }
        lastClock1 = clock1;
        lastClock2 = clock2;
    }

    Tristate Component4013::compute(std::size_t pin) const {
        switch (pin) {
            case 1:  return q1;
            case 2:  return q1Bar;
            case 13: return q2;
            case 12: return q2Bar;
            default: return Tristate::Undefined;
        }
    }

    void Component4013::setLink(std::size_t pin, IComponent& other, std::size_t otherPin) {
        AComponent::setLink(pin, other, otherPin);
    }

    std::string Component4013::getType() const {
        return "4013";
    }
}
/**
** EPITECH PROJECT, 2025
** 4017.cpp
** File description:
** 4017 gate (Johnson Decade Counter) for NanoTekSpice
*/

#include "Advanced_Components/4017.hpp"

namespace nts {
    const std::array<std::size_t, 10> Component4017::outputPins = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11};

    Component4017::Component4017(const std::string& name)
        : AComponent(name), counter(0), lastClock0(Tristate::Undefined), lastClock1(Tristate::Undefined)
    {
    }

    Component4017::~Component4017() {}

    void Component4017::simulate(std::size_t tick) {
        (void)tick;

        auto getValue = [this](std::size_t pin) -> Tristate {
            auto it = inputLinks.find(pin);
            if (it == inputLinks.end() || !it->second.first)
                return Tristate::Undefined;
            return it->second.first->compute(it->second.second);
        };
        Tristate reset = getValue(15);
        Tristate clock0 = getValue(14);
        Tristate clock1 = getValue(13);

        if (reset == Tristate::True) {
            counter = 0;
        } else {
            if (clock0 == Tristate::True && lastClock0 == Tristate::False && clock1 == Tristate::False) {
                counter = (counter + 1) % 10;
            }
            else if (clock1 == Tristate::False && lastClock1 == Tristate::True && clock0 == Tristate::True) {
                counter = (counter + 1) % 10;
            }
        }
        lastClock0 = clock0;
        lastClock1 = clock1;
    }

    Tristate Component4017::compute(std::size_t pin) const {
        if (pin == 12) {
            return (counter >= 5 && counter <= 9) ? Tristate::True : Tristate::False;
        }

        for (int i = 0; i < 10; i++) {
            if (pin == outputPins[i]) {
                return (counter == i) ? Tristate::True : Tristate::False;
            }
        }
        return Tristate::Undefined;
    }

    void Component4017::setLink(std::size_t pin, IComponent& other, std::size_t otherPin) {
        AComponent::setLink(pin, other, otherPin);
    }

    std::string Component4017::getType() const {
        return "4017";
    }
}
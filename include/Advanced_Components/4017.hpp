/**
** EPITECH PROJECT, 2025
** 4017.hpp
** File description:
** 4017 gate (Johnson)
*/

#ifndef COMPONENT_4017_HPP
#define COMPONENT_4017_HPP

#include "AComponent.hpp"
#include <array>

namespace nts {
    class Component4017 : public AComponent {
    public:
        Component4017(const std::string& name);
        ~Component4017() override;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
        std::string getType() const override;

    private:
        int counter;
        Tristate lastClock0;
        Tristate lastClock1;
        
        static const std::array<std::size_t, 10> outputPins;
    };
}

#endif // COMPONENT_4017_HPP
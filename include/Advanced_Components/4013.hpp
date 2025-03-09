/**
** EPITECH PROJECT, 2025
** 4013.hpp
** File description:
** 4013 gate (Flip-Flop)
*/

#ifndef COMPONENT_4013_HPP
#define COMPONENT_4013_HPP

#include "AComponent.hpp"

namespace nts {
    class Component4013 : public AComponent {
    public:
        Component4013(const std::string& name);
        ~Component4013() override;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
        std::string getType() const override;

    private:
        mutable Tristate q1;
        mutable Tristate q1Bar;
        mutable Tristate q2;
        mutable Tristate q2Bar;
        
        Tristate lastClock1;
        Tristate lastClock2;
    };
}

#endif // COMPONENT_4013_HPP
/**
** EPITECH PROJECT, 2025
** 4008.hpp
** File description:
** 4008 gate (4 bits adder)
*/

#ifndef COMPONENT_4008_HPP
#define COMPONENT_4008_HPP

#include "AComponent.hpp"
#include <array>
#include <memory>

namespace nts {
    class Component4008 : public AComponent {
    public:
        Component4008(const std::string& name);
        ~Component4008() override;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
        std::string getType() const override;
    
    private:
        std::array<Tristate, 5> results;
    };
}

#endif // COMPONENT_4008_HPP
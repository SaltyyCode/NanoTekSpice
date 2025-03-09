/*
** EPITECH PROJECT, 2025
** False.hpp
** File description:
** False for NanoTekSpice
*/

#ifndef FALSE_COMPONENT_HPP
#define FALSE_COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
    public:
        FalseComponent(const std::string& name);

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // FALSE_COMPONENT_HPP

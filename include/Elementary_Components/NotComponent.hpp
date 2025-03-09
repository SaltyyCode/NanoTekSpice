/*
** EPITECH PROJECT, 2025
** Not.hpp
** File description:
** Not gate for NanoTekSpice
*/

#ifndef NOT_COMPONENT_HPP
#define NOT_COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
    public:
        NotComponent(const std::string& name);

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // NOT_COMPONENT_HPP
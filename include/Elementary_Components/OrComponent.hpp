/*
** EPITECH PROJECT, 2025
** Or.hpp
** File description:
** Or gate for NanoTekSpice
*/

#ifndef OR_COMPONENT_HPP
#define OR_COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
    public:
        OrComponent(const std::string& name);

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // OR_COMPONENT_HPP
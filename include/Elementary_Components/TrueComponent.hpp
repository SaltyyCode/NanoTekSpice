/*
** EPITECH PROJECT, 2025
** True.hpp
** File description:
** True for NanoTekSpice
*/

#ifndef TRUE_COMPONENT_HPP
#define TRUE_COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
    public:
        TrueComponent(const std::string& name);

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // TRUE_COMPONENT_HPP

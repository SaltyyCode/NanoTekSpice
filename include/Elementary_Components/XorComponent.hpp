/*
** EPITECH PROJECT, 2025
** Xor.hpp
** File description:
** Xor gate for NanoTekSpice
*/

#ifndef XOR_COMPONENT_HPP
#define XOR_COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class XorComponent : public AComponent {
    public:
        XorComponent(const std::string& name);

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // XOR_COMPONENT_HPP

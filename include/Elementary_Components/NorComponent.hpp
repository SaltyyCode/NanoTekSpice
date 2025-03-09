/*
** EPITECH PROJECT, 2025
** Nor.hpp
** File description:
** Nor gate for NanoTekSpice
*/

#ifndef NOR_COMPONENT_HPP
#define NOR_COMPONENT_HPP

#include "AComponent.hpp"
#include <set>

namespace nts {
    class NorComponent : public AComponent {
    public:
        NorComponent(const std::string& name);

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // Nor_COMPONENT_HPP
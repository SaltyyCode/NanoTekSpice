/*
** EPITECH PROJECT, 2025
** NandComponent.hpp
** File description:
** Nand gate for NanoTekSpice
*/

#ifndef NAND_COMPONENT_HPP
#define NAND_COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class NandComponent : public AComponent {
    public:
        explicit NandComponent(const std::string& name);
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // NAND_COMPONENT_HPP

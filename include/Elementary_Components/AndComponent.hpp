/*
** EPITECH PROJECT, 2025
** And.hpp
** File description:
** And gate for NanoTekSpice
*/

#ifndef AND_COMPONENT_HPP
#define AND_COMPONENT_HPP

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
    public:
        AndComponent(const std::string& name);

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) const override;
        std::string getType() const override;
    };
}

#endif // AND_COMPONENT_HPP

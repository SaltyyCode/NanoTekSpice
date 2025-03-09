/*
** EPITECH PROJECT, 2025
** ClockComponent.hpp
** File description:
** Clock.hpp for NanoTekSpice
*/

#ifndef CLOCK_COMPONENT_HPP
#define CLOCK_COMPONENT_HPP

#include "IComponent.hpp"

namespace nts {
    class ClockComponent : public IComponent {
    public:
        ClockComponent(const std::string& name);
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t) const override;
        void setLink(std::size_t, IComponent&, std::size_t) override;
        std::string getName() const override;
        void setState(Tristate newState) override;
        std::string getType() const override;

    private:
        std::string name;
        Tristate state;
        bool manuallySet;
    };
}

#endif // CLOCK_COMPONENT_HPP
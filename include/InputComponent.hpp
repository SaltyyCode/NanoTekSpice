/*
** EPITECH PROJECT, 2025
** Input.hpp
** File description:
** Input for NanoTekSpice
*/

#ifndef INPUT_COMPONENT_HPP
#define INPUT_COMPONENT_HPP

#include "IComponent.hpp"

namespace nts {
    class InputComponent : public IComponent {
    public:
        InputComponent(const std::string& name) : name(name), state(Tristate::Undefined) {}

        void simulate(std::size_t) override {}
        Tristate compute(std::size_t) const override { return state; }
        void setLink(std::size_t, IComponent&, std::size_t) override {}

        std::string getName() const override { return name; }
        void setState(Tristate newState) override { state = newState; }
        std::string getType() const override { return "input"; }


    private:
        std::string name;
        Tristate state;
    };
}

#endif // INPUT_COMPONENT_HPP

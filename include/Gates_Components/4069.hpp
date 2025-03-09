/*
** EPITECH PROJECT, 2025
** 4069.hpp
** File description:
** 4069 gate for NanoTekSpice
*/


#ifndef COMPONENT_4069_HPP
#define COMPONENT_4069_HPP

#include "AComponent.hpp"
#include "Elementary_Components/NotComponent.hpp"
#include <array>
#include <memory>


namespace nts {
    class Component4069 : public AComponent {
public:
    Component4069(const std::string& name);
    ~Component4069() override;
    void simulate(std::size_t tick) override;
    Tristate compute(std::size_t pin) const override;
    void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
    std::string getType() const override;

private:
    std::array<std::shared_ptr<NotComponent>, 6> gates;
    };
}

#endif // COMPONENT_4030_HPP

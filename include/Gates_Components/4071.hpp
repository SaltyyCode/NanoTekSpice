/*
** EPITECH PROJECT, 2025
** 4071.hpp
** File description:
** 4071 gate for NanoTekSpice
*/

#ifndef COMPONENT_4071_HPP
#define COMPONENT_4071_HPP

#include "AComponent.hpp"
#include "Elementary_Components/OrComponent.hpp"
#include <array>
#include <memory>


namespace nts {
    class Component4071 : public AComponent {
public:
    Component4071(const std::string& name);
    ~Component4071() override;
    void simulate(std::size_t tick) override;
    Tristate compute(std::size_t pin) const override;
    void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
    std::string getType() const override;

private:
    std::array<std::shared_ptr<OrComponent>, 4> gates;
    };
}

#endif // COMPONENT_4071_HPP

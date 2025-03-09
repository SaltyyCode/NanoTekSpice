/*
** EPITECH PROJECT, 2025
** 4030.hpp
** File description:
** 4030 gate for NanoTekSpice
*/


#ifndef COMPONENT_4030_HPP
#define COMPONENT_4030_HPP

#include "AComponent.hpp"
#include "Elementary_Components/XorComponent.hpp"
#include <array>
#include <memory>


namespace nts {
    class Component4030 : public AComponent {
public:
    Component4030(const std::string& name);
    ~Component4030() override;
    void simulate(std::size_t tick) override;
    Tristate compute(std::size_t pin) const override;
    void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
    std::string getType() const override;

private:
    std::array<std::shared_ptr<XorComponent>, 4> gates;
    };
}

#endif // COMPONENT_4030_HPP

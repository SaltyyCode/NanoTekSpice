/*
** EPITECH PROJECT, 2025
** 4081.hpp
** File description:
** 4081 gate for NanoTekSpice
*/

#ifndef COMPONENT_4081_HPP
#define COMPONENT_4081_HPP

#include "AComponent.hpp"
#include "Elementary_Components/AndComponent.hpp"
#include <array>
#include <memory>

namespace nts {
    class Component4081 : public AComponent {
public:
    Component4081(const std::string& name);
    ~Component4081() override;
    void simulate(std::size_t tick) override;
    Tristate compute(std::size_t pin) const override;
    void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
    std::string getType() const override;

private:
    std::array<std::shared_ptr<AndComponent>, 4> gates;
    };
}

#endif // COMPONENT_4081_HPP

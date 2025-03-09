/*
** EPITECH PROJECT, 2025
** 4011.hpp
** File description:
** 4011 gate for NanoTekSpice
*/

#ifndef COMPONENT_4011_HPP
#define COMPONENT_4011_HPP

#include "AComponent.hpp"
#include "Elementary_Components/NandComponent.hpp"
#include <array>
#include <memory>

namespace nts {
    class Component4011 : public AComponent {
public:
    Component4011(const std::string& name);
    ~Component4011() override;
    void simulate(std::size_t tick) override;
    Tristate compute(std::size_t pin) const override;
    void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
    std::string getType() const override;

private:
    std::array<std::shared_ptr<NandComponent>, 4> gates;
    };
}

#endif // COMPONENT_4011_HPP

/*
** EPITECH PROJECT, 2025
** 4001.hpp
** File description:
** 4001 gate for NanoTekSpice
*/

#ifndef COMPONENT_4001_HPP
#define COMPONENT_4001_HPP

#include "AComponent.hpp"
#include "Elementary_Components/NorComponent.hpp"
#include <array>
#include <memory>

namespace nts {
    class Component4001 : public AComponent {
public:
    Component4001(const std::string& name);
    ~Component4001() override;
    void simulate(std::size_t tick) override;
    Tristate compute(std::size_t pin) const override;
    void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;
    std::string getType() const override;

private:
    std::array<std::shared_ptr<NorComponent>, 4> gates;
    };
}

#endif // COMPONENT_4001_HPP

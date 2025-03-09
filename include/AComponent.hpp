/*
** EPITECH PROJECT, 2025
** AComponent.hpp
** File description:
** Abstract class for NanoTekSpice
*/

#ifndef A_COMPONENT_HPP
#define A_COMPONENT_HPP

#include "IComponent.hpp"
#include <map>
#include <string>
#include <utility>

namespace nts {
    class AComponent : public IComponent {
    public:
        AComponent(const std::string& name);
        virtual ~AComponent() = default;

        void simulate(std::size_t tick) override;
        virtual Tristate compute(std::size_t pin) const override = 0;
        void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;

        std::string getName() const override;
        void setState(Tristate newState) override;
        virtual std::string getType() const override = 0;

    protected:
        std::string name;
        Tristate state;
        std::map<std::size_t, std::pair<IComponent*, std::size_t>> inputLinks;
    };
}

#endif // A_COMPONENT_HPP

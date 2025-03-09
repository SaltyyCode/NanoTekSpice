/*
** EPITECH PROJECT, 2025
** IComponent.hpp
** File description:
** IComponent for NanoTekSpice
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <cstddef>
#include <string>

namespace nts {
    enum class Tristate {
        Undefined = -1,
        False = 0,
        True = 1
    };

    class IComponent {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) const = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual std::string getType() const = 0;
        virtual std::string getName() const = 0;
        virtual void setState(Tristate state) = 0;
        virtual std::string getStateAsString() const {
            switch (compute(1)) {
                case Tristate::True: return "1";
                case Tristate::False: return "0";
                default: return "U";
            }
        }
    };
}
#endif // ICOMPONENT_HPP

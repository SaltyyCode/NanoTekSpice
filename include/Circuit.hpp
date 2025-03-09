/*
** EPITECH PROJECT, 2025
** Circuit.hpp
** File description:
** Circuit.hpp for NanoTekSpice
*/

#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <vector>
#include <memory>
#include "IComponent.hpp"
#include "Parser.hpp"

namespace nts {
    class Circuit {
    public:
        void loadFile(const std::string& filename);
        void displayContent() const;
        void simulate();
        bool setInputValue(const std::string& name, Tristate value);
        const std::vector<std::shared_ptr<IComponent>>& getInputs() const;
        const std::vector<std::shared_ptr<IComponent>>& getOutputs() const;
    private:
        std::vector<std::shared_ptr<IComponent>> components;
        std::vector<std::shared_ptr<IComponent>> inputs;
        std::vector<std::shared_ptr<IComponent>> outputs;
        Parser parser;
    };
}

#endif // CIRCUIT_HPP

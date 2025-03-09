/*
** EPITECH PROJECT, 2025
** Parser.hpp
** File description:
** Parser for NanoTekSpice
*/

#pragma once
#include <string>
#include <vector>
#include <utility>
#include <set>

namespace nts {
    class Parser {
        public:
            struct Chipset {
                std::string type;
                std::string name;
            };

            struct Link {
                std::string component1;
                size_t pin1;
                std::string component2;
                size_t pin2;
            };

            void parseFile(const std::string& filename);
            const std::vector<Chipset>& getChipsets() const;
            const std::vector<Link>& getLinks() const;

        private:
            std::vector<Chipset> chipsets;
            std::vector<Link> links;

            static const std::set<std::string> validTypes;
            
            void parseChipsetLine(const std::string& line);
            void parseLinkLine(const std::string& line);
            std::pair<std::string, size_t> parseComponentPin(const std::string& str);
            static std::string trim(const std::string& str);
            bool isValidComponentType(const std::string& type) const;
    };
}
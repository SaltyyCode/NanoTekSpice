#include "Parser.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

namespace nts {
    const std::set<std::string> Parser::validTypes = {

        "input",
        "output",
        "true",
        "false",
        "clock",

        "and",
        "or",
        "xor",
        "not",
        "nor",
        "nand",

       
        "4001",  
        "4011",  
        "4030",  
        "4069",  
        "4071",  
        "4081",   

      
        "4008",  
        "4013",   
        "4017",   
        "4040",   
        "4094",   
        "4512",  
        "4514",   
        "4801",   
        "2716", 
        "logger"
    };

    bool Parser::isValidComponentType(const std::string& type) const
    {
        return validTypes.find(type) != validTypes.end();
    }

    void Parser::parseFile(const std::string& filename)
    {
        std::ifstream file(filename);

        if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".nts") {
            throw std::runtime_error("Invalid file extension: file must be a .nts file");
        }

        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }

        enum class Section { NONE, CHIPSETS, LINKS } currentSection = Section::NONE;
        std::string line;

        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#')
                continue;

            line = trim(line);
            if (line.empty())
                continue;

            if (line == ".chipsets:") {
                currentSection = Section::CHIPSETS;
                continue;
            }
            if (line == ".links:") {
                currentSection = Section::LINKS;
                continue;
            }

            try {
                switch (currentSection) {
                    case Section::CHIPSETS:
                        parseChipsetLine(line);
                        break;
                    case Section::LINKS:
                        parseLinkLine(line);
                        break;
                    default:
                        throw std::runtime_error("Invalid section or missing section header");
                }
            } catch (const std::exception& e) {
                throw std::runtime_error("Error parsing line '" + line + "': " + e.what());
            }
        }

        if (chipsets.empty()) {
            throw std::runtime_error("No chipsets in circuit");
        }
    }

    void Parser::parseChipsetLine(const std::string& line)
    {
        std::istringstream iss(line);
        Chipset chipset;
        
        if (!(iss >> chipset.type >> chipset.name)) {
            throw std::runtime_error("Invalid chipset format");
        }

        if (!isValidComponentType(chipset.type)) {
            throw std::runtime_error("Invalid component type: " + chipset.type);
        }

        auto it = std::find_if(chipsets.begin(), chipsets.end(),
            [&](const Chipset& c) { return c.name == chipset.name; });
        if (it != chipsets.end()) {
            throw std::runtime_error("Duplicate component name: " + chipset.name);
        }

        chipsets.push_back(chipset);
    }

    void Parser::parseLinkLine(const std::string& line)
    {
        std::istringstream iss(line);
        std::string link1, link2;
        
        if (!(iss >> link1 >> link2)) {
            throw std::runtime_error("Invalid link format");
        }

        auto [comp1, pin1] = parseComponentPin(link1);
        auto [comp2, pin2] = parseComponentPin(link2);

        auto findComponent = [this](const std::string& name) {
            return std::find_if(chipsets.begin(), chipsets.end(),
                [&](const Chipset& c) { return c.name == name; }) != chipsets.end();
        };

        if (!findComponent(comp1)) {
            throw std::runtime_error("Unknown component: " + comp1);
        }
        if (!findComponent(comp2)) {
            throw std::runtime_error("Unknown component: " + comp2);
        }

        links.push_back({comp1, pin1, comp2, pin2});
    }

    std::pair<std::string, size_t> Parser::parseComponentPin(const std::string& str)
    {
        auto pos = str.find(':');
        if (pos == std::string::npos) {
            throw std::runtime_error("Invalid component:pin format: " + str);
        }

        std::string comp = str.substr(0, pos);
        size_t pin;
        try {
            pin = std::stoul(str.substr(pos + 1));
        } catch (...) {
            throw std::runtime_error("Invalid pin number in: " + str);
        }

        return {comp, pin};
    }

    std::string Parser::trim(const std::string& str)
    {
        auto start = str.find_first_not_of(" \t");
        if (start == std::string::npos)
            return "";
        auto end = str.find_last_not_of(" \t");
        return str.substr(start, end - start + 1);
    }

    const std::vector<Parser::Chipset>& Parser::getChipsets() const
    {
        return chipsets;
    }

    const std::vector<Parser::Link>& Parser::getLinks() const
    {
        return links;
    }
}
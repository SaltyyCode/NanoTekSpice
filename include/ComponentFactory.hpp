/*
** EPITECH PROJECT, 2025
** ComponentFactory.hpp
** File description:
** ComponentFactory for NanoTekSpice
*/

#ifndef COMPONENT_FACTORY_HPP
#define COMPONENT_FACTORY_HPP

#include "IComponent.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "ClockComponent.hpp"

#include "Elementary_Components/TrueComponent.hpp"
#include "Elementary_Components/FalseComponent.hpp"
#include "Elementary_Components/AndComponent.hpp"
#include "Elementary_Components/OrComponent.hpp"
#include "Elementary_Components/XorComponent.hpp"
#include "Elementary_Components/NotComponent.hpp"
#include "Elementary_Components/NorComponent.hpp"
#include "Elementary_Components/NandComponent.hpp"

#include "Gates_Components/4071.hpp"
#include "Gates_Components/4081.hpp"
#include "Gates_Components/4030.hpp"
#include "Gates_Components/4069.hpp"
#include "Gates_Components/4001.hpp"
#include "Gates_Components/4011.hpp"

#include "Advanced_Components/4008.hpp"
#include "Advanced_Components/4013.hpp"
#include "Advanced_Components/4017.hpp"
/*#include "Advanced_Components/4040.hpp"
#include "Advanced_Components/4094.hpp"
#include "Advanced_Components/4512.hpp"
#include "Advanced_Components/4514.hpp"
#include "Advanced_Components/4801.hpp"
#include "Advanced_Components/2716.hpp"
#include "Advanced_Components/Logger.hpp" */

#include <memory>
#include <string>
#include <map>
#include <functional>
#include <stdexcept>

namespace nts {
    class ComponentFactory {
    public:
        ComponentFactory()
        {
            factories = {
                {"input", [this] (const std::string& name) { return createInput(name); }},
                {"output", [this] (const std::string& name) { return createOutput(name); }},
                {"true", [this] (const std::string& name) { return createTrue(name); }},
                {"false", [this] (const std::string& name) { return createFalse(name); }},
                {"clock", [this] (const std::string& name) { return createClock(name); }},
                {"and", [this] (const std::string& name) { return createAnd(name); }},
                {"or", [this] (const std::string& name) { return createOr(name); }},
                {"xor", [this] (const std::string& name) { return createXor(name); }},
                {"not", [this] (const std::string& name) { return createNot(name); }},
                {"nor", [this] (const std::string& name) { return createNor(name); }},
                {"nand", [this] (const std::string& name) { return createNand(name); }},
                {"4071", [this] (const std::string& name) { return create4071(name); }},
                {"4081", [this] (const std::string& name) { return create4081(name); }},
                {"4030", [this] (const std::string& name) { return create4030(name); }},
                {"4069", [this] (const std::string& name) { return create4069(name); }},
                {"4001", [this] (const std::string& name) { return create4001(name); }},
                {"4011", [this] (const std::string& name) { return create4011(name); }},
                {"4008", [this] (const std::string& name) { return create4008(name); }},
              {"4013", [this] (const std::string& name) { return create4013(name); }},
                {"4017", [this] (const std::string& name) { return create4017(name); }},
                /*{"4040", [this] (const std::string& name) { return create4040(name); }},
                {"4094", [this] (const std::string& name) { return create4094(name); }},
                {"4512", [this] (const std::string& name) { return create4512(name); }},
                {"4514", [this] (const std::string& name) { return create4514(name); }},
                {"4801", [this] (const std::string& name) { return create4801(name); }},
                {"2716", [this] (const std::string& name) { return create2716(name); }},
                {"logger", [this] (const std::string& name) { return createLogger(name); }} */
            };
        }

        std::unique_ptr<IComponent> createComponent(const std::string& type, const std::string& name)
        {
            auto it = factories.find(type);
            if (it != factories.end()) {
                return it->second(name);
            }
            throw std::runtime_error("Unknown component type: " + type);
        }

    private:
        std::map<std::string, std::function<std::unique_ptr<IComponent>(const std::string&)>> factories;

        std::unique_ptr<IComponent> createInput(const std::string& name) const { return std::make_unique<InputComponent>(name); }
        std::unique_ptr<IComponent> createTrue(const std::string& name) const { return std::make_unique<TrueComponent>(name); }
        std::unique_ptr<IComponent> createFalse(const std::string& name) const { return std::make_unique<FalseComponent>(name); }
        std::unique_ptr<IComponent> createOutput(const std::string& name) const { return std::make_unique<OutputComponent>(name); }
        std::unique_ptr<IComponent> createClock(const std::string& name) const { return std::make_unique<ClockComponent>(name); }
        std::unique_ptr<IComponent> createAnd(const std::string& name) const { return std::make_unique<AndComponent>(name); }
        std::unique_ptr<IComponent> createOr(const std::string& name) const { return std::make_unique<OrComponent>(name); }
        std::unique_ptr<IComponent> createXor(const std::string& name) const { return std::make_unique<XorComponent>(name); }
        std::unique_ptr<IComponent> createNot(const std::string& name) const { return std::make_unique<NotComponent>(name); }
        std::unique_ptr<IComponent> createNor(const std::string& name) const { return std::make_unique<NorComponent>(name); }
        std::unique_ptr<IComponent> createNand(const std::string& name) const { return std::make_unique<NandComponent>(name); }
        std::unique_ptr<IComponent> create4071(const std::string& name) const { return std::make_unique<Component4071>(name); }
        std::unique_ptr<IComponent> create4081(const std::string& name) const { return std::make_unique<Component4081>(name); }
        std::unique_ptr<IComponent> create4030(const std::string& name) const { return std::make_unique<Component4030>(name); }
        std::unique_ptr<IComponent> create4069(const std::string& name) const { return std::make_unique<Component4069>(name); }
        std::unique_ptr<IComponent> create4001(const std::string& name) const { return std::make_unique<Component4001>(name); }
        std::unique_ptr<IComponent> create4011(const std::string& name) const { return std::make_unique<Component4011>(name); }
        std::unique_ptr<IComponent> create4008(const std::string& name) const { return std::make_unique<Component4008>(name); }
        std::unique_ptr<IComponent> create4013(const std::string& name) const { return std::make_unique<Component4013>(name); }
        std::unique_ptr<IComponent> create4017(const std::string& name) const { return std::make_unique<Component4017>(name); }
        /*std::unique_ptr<IComponent> create4040(const std::string& name) const { return std::make_unique<Component4040>(name); }
        std::unique_ptr<IComponent> create4094(const std::string& name) const { return std::make_unique<Component4094>(name); }
        std::unique_ptr<IComponent> create4512(const std::string& name) const { return std::make_unique<Component4512>(name); }
        std::unique_ptr<IComponent> create4514(const std::string& name) const { return std::make_unique<Component4514>(name); }
        std::unique_ptr<IComponent> create4801(const std::string& name) const { return std::make_unique<Component4801>(name); }
        std::unique_ptr<IComponent> create2716(const std::string& name) const { return std::make_unique<Component2716>(name); }
        std::unique_ptr<IComponent> createLogger(const std::string& name) const { return std::make_unique<LoggerComponent>(name); } */
    };
}

#endif // COMPONENT_FACTORY_HPP

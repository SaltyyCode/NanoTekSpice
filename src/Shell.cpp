/*
** EPITECH PROJECT, 2025
** Shell.cpp
** File description:
** Shell for NanoTekSpice
*/

#include "Shell.hpp"
#include "ClockComponent.hpp"

std::atomic<bool> nts::Shell::running = true;

nts::Shell::Shell(Circuit& circuit) : circuit(circuit) {}

void nts::Shell::run() {
    std::string command;
    
    while (running) {
        std::cout << "> ";
        if (!std::getline(std::cin, command))
            break;
        handleCommand(command);
    }
}

void nts::Shell::handleCommand(const std::string &command) {
    if (command == "exit") {
        commandExit();
    } else if (command == "display") {
        commandDisplay();
    } else if (command == "simulate") {
        commandSimulate();
    } else if (command == "loop") {
        commandLoop();
    } else if (command.find("=") != std::string::npos) {
        commandInput(command);
    } else if (command == "sd") {
        commandSimulateDisplay();
    } else {
        std::cout << "Unknown command" << std::endl;
    }
}

void nts::Shell::commandExit() {
    running = false;
}

void nts::Shell::commandDisplay() {
    std::cout << "tick: " << tick << std::endl;

    std::vector<std::shared_ptr<IComponent>> sortedInputs = circuit.getInputs();
    std::sort(sortedInputs.begin(), sortedInputs.end(), [](const auto& a, const auto& b) {
        return a->getName() < b->getName();
    });

    std::cout << "input(s):" << std::endl;
    for (const auto& input : sortedInputs) {
        std::cout << "  " << input->getName() << ": " << input->getStateAsString() << std::endl;
    }

    std::vector<std::shared_ptr<IComponent>> sortedOutputs = circuit.getOutputs();
    std::sort(sortedOutputs.begin(), sortedOutputs.end(), [](const auto& a, const auto& b) {
        return a->getName() < b->getName();
    });

    std::cout << "output(s):" << std::endl;
    for (const auto& output : sortedOutputs) {
        std::cout << "  " << output->getName() << ": " << output->getStateAsString() << std::endl;
    }
}

void nts::Shell::commandSimulate() 
{
    tick++;

    for (const auto& [name, value] : pendingInputs) {
        circuit.setInputValue(name, value);
    }
    pendingInputs.clear();
    circuit.simulate();
}

void nts::Shell::handleSignal(int sig) {
    (void)sig;
    std::cout << "\nExiting loop..." << std::endl;
    nts::Shell::running = false;
}

void nts::Shell::commandLoop() {
    running = true;
    signal(SIGINT, nts::Shell::handleSignal);

    while (running) {
        commandSimulate();
        commandDisplay();
    }
    signal(SIGINT, SIG_DFL);
}

void nts::Shell::commandInput(const std::string &input) {
    auto pos = input.find("=");
    if (pos == std::string::npos) {
        std::cerr << "Invalid input format. Use input=value" << std::endl;
        return;
    }

    std::string name = input.substr(0, pos);
    std::string value = input.substr(pos + 1);

    nts::Tristate newValue;
    if (value == "0") newValue = nts::Tristate::False;
    else if (value == "1") newValue = nts::Tristate::True;
    else if (value == "U") newValue = nts::Tristate::Undefined;
    else {
        std::cerr << "Invalid value. Must be 0, 1, or U." << std::endl;
        return;
    }
    pendingInputs[name] = newValue;
}

void nts::Shell::commandSimulateDisplay()
{   
    commandSimulate();
    commandDisplay();
}
/*
** EPITECH PROJECT, 2025
** Shell.hpp
** File description:
** Shell for NanoTekSpice
*/

#ifndef SHELL_HPP
#define SHELL_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <csignal>
#include <atomic>
#include <algorithm>
#include "Circuit.hpp"

namespace nts {
    class Shell {
    public:
        Shell(Circuit& circuit);
        void run();
    private:
        void handleCommand(const std::string &command);
        void commandExit();
        void commandDisplay();
        void commandSimulate();
        void commandLoop();
        void commandInput(const std::string &input);
        void commandSimulateDisplay();
        static void handleSignal(int sig);
        static std::atomic<bool> running;
        Circuit& circuit;
        size_t tick = 0;
        std::unordered_map<std::string, Tristate> pendingInputs;
    };
}

#endif // SHELL_HPP

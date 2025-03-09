/*
** EPITECH PROJECT, 2025
** Nts.cpp
** File description:
** NanoTekSpice main file
*/

#include "Shell.hpp"
#include "Circuit.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <circuit_file>" << std::endl;
        return 84;
    }

    try {
        nts::Circuit circuit;
        circuit.loadFile(argv[1]);
        //circuit.displayContent();
        nts::Shell shell(circuit);
        shell.run();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}

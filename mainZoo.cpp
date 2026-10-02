#include "zoologico.h"
#include <iostream>

int main() {
    Zoologico zoo;

    zoo.adicionar(1, "Alex", 250);
    zoo.adicionar(2, "Zé", 0.4);
    zoo.adicionar(3, "Dumbo", 4500);
    zoo.adicionar(2, "Luís", 0.6);
    zoo.adicionar(1,"Alex", 300);
    zoo.adicionar(4, "Pô", 675);

    std::cout << std::endl;

    zoo.listar();

    std::cout << std::endl;

    std::cout << "Ração necessária para suprir essa demanda: " << zoo.racaoTotal() << "kg" << std::endl;

    std::cout << std::endl;

    zoo.remover("Zé");
    zoo.remover("Dumbo");
    zoo.remover("Maurice");

    std::cout << std::endl;

    zoo.listar();

    std::cout << std::endl;

    std::cout << "Ração necessária para suprir essa demanda: " << zoo.racaoTotal() << "kg" << std::endl;

    std::cout << std::endl;

    return 0;
}
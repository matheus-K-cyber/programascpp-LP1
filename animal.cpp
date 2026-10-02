#include "animal.h"
#include <iostream>

Animal::Animal(std::string n, double p) : nome(n), peso(p) {}

Animal::~Animal() {
    std::cout << nome << " movido para outro zoológico!" << std::endl;
}

std::string Animal::getNome() { return nome; }

void Animal::exibir() {
    std::cout << "Este " << nome << " come " << racaoDiaria() << "kg de ração por dia" << std::endl;
}
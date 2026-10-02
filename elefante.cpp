#include "elefante.h"
#include <iostream>

Elefante::Elefante(std::string ap, double p) : Animal(ap, p) {}

double Elefante::racaoDiaria() { return peso * 0.1; }

void Elefante::exibir() {
    std::cout << "[Elefante]" << nome << " acaba de chegar ao nosso zoológico com " << peso << "kg de peso!" << std::endl;
    Animal::exibir();
}
#include "papagaio.h"
#include <iostream>

Papagaio::Papagaio(std::string ap, double p) : Animal(ap, p) {}

double Papagaio::racaoDiaria() { return peso * 0.1; }

void Papagaio::exibir() {
    std::cout << "[Papagaio]" << nome << " acaba de chegar ao nosso zoológico com " << peso << "kg de peso!" << std::endl;
    Animal::exibir();
}
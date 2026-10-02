#include "leao.h"
#include <iostream>

Leao::Leao(std::string ap, double p) : Animal(ap, p) {}

double Leao::racaoDiaria() { return peso * 0.05; }

void Leao::exibir() {
    std::cout << "[Leão]" << nome << " acaba de chegar ao nosso zoológico com " << peso << "kg de peso!" << std::endl;
    Animal::exibir();
}
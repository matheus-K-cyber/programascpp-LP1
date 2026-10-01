#include <iostream>
#include "forma.h"

Forma::Forma(std::string n) : nome(n) {}

Forma::~Forma() {
    std::cout << "Destruindo " << nome << std::endl;
}

std::string Forma::getNome() { return nome; }

void Forma::exibir() {
    std::cout << nome << ": area " << calcularArea() << std::endl;
}
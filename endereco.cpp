#include "endereco.h"
#include <iostream>
#include <string>

Endereco::Endereco(std::string r, int num, std::string city) : rua(r), numero(num), cidade(city) {}

void Endereco::exibir() {
    std::cout << "Rua: " << rua << "\n";
    std::cout << "Número: " << numero << "\n";
    std::cout << "Cidade: " << cidade << std::endl;
}
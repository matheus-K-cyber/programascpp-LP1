#include "pessoa.h"
#include <iostream>
#include <string>

Pessoa::Pessoa(std::string n, Endereco loc) : nome(n), localizacao(loc) {}

void Pessoa::exibir() {
    std::cout << "Localização de " << nome << " é esta:\n";
    localizacao.exibir();
}
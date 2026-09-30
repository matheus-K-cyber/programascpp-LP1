#include "endereco.h"
#include "pessoa.h"
#include <iostream>

int main() {
    Endereco lo("Dawn Salvador", 3222, "Novo Horizonte");
    
    std::cout << "Endereço(dono não-identificado):" << std::endl;
    lo.exibir();

    Pessoa pes("Philip", lo);

    std::cout << "Endereço(dono identificado):" << std::endl;
    pes.exibir();

    return 0;
}
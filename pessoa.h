#ifndef PESSOA_H
#define PESSOA_H

#include "endereco.h"
#include <string>

class Pessoa {
    private:
        std::string nome;
        Endereco localizacao;

    public:
        Pessoa(std::string n, Endereco loc);

        void exibir();
};

#endif
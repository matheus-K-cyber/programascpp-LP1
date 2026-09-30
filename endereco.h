#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

class Endereco {
    private:
        std::string rua;
        int numero;
        std::string cidade;

    public:
        Endereco(std::string r, int num, std::string city);

        void exibir();
};

#endif
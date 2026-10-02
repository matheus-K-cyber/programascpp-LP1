#ifndef ZOOLOGICO_H
#define ZOOLOGICO_H

#include "animal.h"
#include <vector>
#include <string>

class Zoologico {
    private:
        std::vector<Animal*> animais;
        Animal* buscar(std::string nome);

    public:
        Zoologico();
        ~Zoologico();

        void adicionar(int tipo, std::string nome, double peso);
        void remover(std::string nome);
        void listar();
        double racaoTotal();
};

#endif
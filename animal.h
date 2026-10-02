#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
    protected:
        std::string nome;
        double peso;

    public:
        Animal(std::string n, double p);
        virtual ~Animal();

        std::string getNome();
        
        virtual double racaoDiaria() = 0;

        virtual void exibir();
};

#endif
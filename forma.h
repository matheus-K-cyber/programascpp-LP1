#ifndef FORMA_H
#define FORMA_H

#include <string>

class Forma {
    protected:
        std::string nome;
        
    public:
        Forma(std::string n);
        virtual ~Forma();
        std::string getNome();
        virtual double calcularArea() = 0;
        virtual void exibir();
};

#endif
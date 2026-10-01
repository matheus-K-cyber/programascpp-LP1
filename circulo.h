#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

class Circulo : public Forma {
    private:
        double raio;

    public:
        Circulo(double r);
        
        double calcularArea() override;

        void exibir() override;
};

#endif
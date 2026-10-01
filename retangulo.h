#ifndef RETANGULO_H
#define RETANGULO_H

#include "forma.h"

class Retangulo : public Forma {
    private:
        double largura;
        double altura;

    public:
        Retangulo(double l, double a);
        
        double calcularArea() override;
};

#endif
#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "forma.h"

class Triangulo : public Forma {
    private:
        double lado, sp;

    public:
        Triangulo(double l);

        double calcularArea() override;
};

#endif
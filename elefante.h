#ifndef ELEFANTE_H
#define ELEFANTE_H

#include "animal.h"

class Elefante : public Animal {
    public:
        Elefante(std::string ap, double p);

        double racaoDiaria() override;

        void exibir() override;
};

#endif
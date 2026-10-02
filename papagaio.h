#ifndef PAPAGAIO_H
#define PAPAGAIO_H

#include "animal.h"

class Papagaio : public Animal {
    public:
        Papagaio(std::string ap, double p);

        double racaoDiaria() override;

        void exibir() override;
};

#endif
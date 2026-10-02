#ifndef LEAO_H
#define LEAO_H

#include "animal.h"

class Leao : public Animal {
    public:
        Leao(std::string ap, double p);

        double racaoDiaria() override;

        void exibir();
};

#endif
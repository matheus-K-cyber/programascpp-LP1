#include <iostream>
#include <vector>
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"

int main() {
    std::vector<Forma*> formas;

    formas.push_back(new Retangulo(4, 3));
    formas.push_back(new Circulo(1));
    formas.push_back(new Retangulo(2, 5));
    formas.push_back(new Triangulo(5));

    for (size_t i = 0; i < formas.size(); i++) {
        formas[i]->exibir();
    }
    for (size_t i = 0; i < formas.size(); i++) {
        delete formas[i];
    }
    formas.clear();

return 0;
}
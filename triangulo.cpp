#include "triangulo.h"
#include <cmath>

Triangulo::Triangulo(double l) : Forma("Triangulo"), lado(l) {}

double Triangulo::calcularArea() {
    sp = (lado + lado + lado) / 2;

    return sqrt(sp * (sp - lado) * (sp - lado) * (sp - lado));
}
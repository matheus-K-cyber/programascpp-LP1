#include <iostream>
#include "circulo.h"

Circulo::Circulo(double r) : Forma("Circulo"), raio(r) {}

double Circulo::calcularArea() { return 3.14159 * raio * raio; }

void Circulo::exibir() {
std::cout << "Circulo de raio " << raio << ": area " << calcularArea() << "m²" << std::endl;
}
#include "retangulo.h"

Retangulo::Retangulo(double l, double a) : Forma("Retangulo"), largura(l), altura(a) {}

double Retangulo::calcularArea() { return largura * altura; }
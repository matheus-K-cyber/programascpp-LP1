#include <iostream>
#include <iomanip>

class Retangulo {
    public:
    
        float altura, largura;

        Retangulo(float alt, float larg) {
            std::cout << "Retângulo criado com altura = " << alt << "m e largura = " << larg << "m" << std::endl;
            altura = alt;
            largura = larg;
        }

        void exibir() {
            std::cout << "O retângulo de altura " << altura << "m e largura " << largura << "m possui área = ";
            std::cout << std::fixed << std::setprecision(2) << largura * altura << "m²" << std::endl;
        }
};

int main() {
    Retangulo ret1(10.30, 15.00);
    Retangulo ret2(5.00, 20.00);
    Retangulo ret3(15.33, 30.27);

    std::cout << "\n";

    ret1.exibir();
    ret2.exibir();
    ret3.exibir();

    return 0;
}
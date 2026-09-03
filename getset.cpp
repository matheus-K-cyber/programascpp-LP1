#include <iostream>
#include <iomanip>

class Retangulo {
    private:
        double largura, altura;

    public:
        Retangulo(double l, double a) {
            setLargura(l);
            setAltura(a);
        }

        double getLargura() {
            return largura;
        }

        double getAltura() {
            return altura;
        }

        void setLargura(double l) {
            if(l <= 0) {
                std::cout << "Valor inválido! Largura mantida com o valor original..." << std::endl;
            } else {
                largura = l;
            }
        }

        void setAltura(double a) {
            if(a <= 0) {
                std::cout << "Valor inválido! Altura mantina com o valor original..." << std::endl;
            } else {
                altura = a;
            }
        }

        void plus() {
            std::cout << "Área deste retângulo: " << std::fixed << std::setprecision(2) 
            << largura * altura << "m²" << std::endl;
            std::cout << "Perímetro deste retângulo: " << std::fixed << std::setprecision(2) 
            << 2 * (largura + altura) << "m" << std::endl;
        }

        void exibir() {
            std::cout << "Largura: " << largura << "m altura: " << altura << "m" << std::endl;
            std::cout << "Dados adicionais:\n";
            plus();
            std::cout << std::endl;
        }
};

int main() {
    Retangulo ret(13.22, 15.41);

    ret.exibir();

    std::cout << "Largura: " << ret.getLargura() << std::endl;
    std::cout << "Altura: " << ret.getAltura() << std::endl;

    ret.setLargura(20.00);
    ret.setAltura(12.33);

    ret.exibir();

    ret.setLargura(-12.44);
    ret.setAltura(0.00);
    ret.exibir();

    return 0;
}
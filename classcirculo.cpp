#include <iostream>

class Circulo {
    public:

        double raio;

        double calcularArea() {
            return 3.14 * raio * raio;
        }

        double calcularCircunferencia() {
            return 2 * 3.14 * raio; 
        }

        bool ehMaiorQue(Circulo outro) {
            return raio > outro.raio;
        }

        void exibirInfo() {
            std::cout << "Raio: " << raio << std::endl;
            std::cout << "Área: " << calcularArea() << std::endl;
            std::cout << "Circunferência: " << calcularCircunferencia() << std::endl;
        }
};

int main() {
    Circulo circu, outro;

    circu.raio = 10.0;
    outro.raio = 5.0;

    std::cout << "Primeiro circulo: " << std::endl;
    circu.exibirInfo();

    std::cout << "Este circulo é maior? " << (circu.ehMaiorQue(outro) ? "Sim" : "Não") << std::endl;
    
    return 0;
}
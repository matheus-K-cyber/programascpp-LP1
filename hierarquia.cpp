#include <iostream>

class Forma {
    protected:
        double valor;
    
    public:
        Forma(double v) {
            valor = v;

            std::cout << "Valor usado: " << valor << std::endl;
        }

        virtual double calcArea() {
            return valor;
        }

        virtual void exibir() {
            std::cout << "Área sem forma: " << calcArea() << std::endl;
        }
};

class Circulo : public Forma{
    public:
        Circulo(double v) : Forma(v){
            std::cout << "Círculo com raio " << valor << " criado!" << std::endl;
        }

        double calcArea() override {
            return (valor * valor) * 3.14;
        }

        void exibir() override {
            std::cout << "Área do círculo: " << calcArea() << std::endl;
        }
};

class Quadrado : public Forma{
    public:
        Quadrado(double v) : Forma(v){
            std::cout << "Quadrado com lado " << valor << " criado!" << std::endl;
        }

        double calcArea() override {
            return valor * valor;
        }

        void exibir() override {
            std::cout << "Área do quadrado: " << calcArea() << std::endl;
        }
};

int main() {
    Forma f(2.74);
    f.calcArea();
    f.exibir();
    std::cout << std::endl;

    Circulo circu(5.5);
    circu.calcArea();
    circu.exibir();
    std::cout << std::endl;

    Quadrado quadra(15.5);
    quadra.calcArea();
    quadra.exibir();
    std::cout << std::endl;

    return 0;
}
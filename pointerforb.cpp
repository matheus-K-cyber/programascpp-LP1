#include <iostream>
#include <string>
#include <cmath>

class Forma {
    protected:
        std::string nome;

    public:
        Forma(std::string form) : nome(form) {}

        virtual double calcularArea() = 0;

        virtual void exibir() {
            std::cout << nome << " com área: " << calcularArea() << std::endl;
        }

        virtual ~Forma() {
            std::cout << nome << " destruído" << std::endl;
        }
};

class Retangulo : public Forma {
    private:
        double largura, altura;

    public:
        Retangulo(double l, double a) : Forma("Retangulo"), largura(l), altura(a) {}

        double calcularArea() override {
            return largura * altura;
        }
};

class Circulo : public Forma {
    private:
        double raio;

    public:
        Circulo(double r) : Forma("Circulo"), raio(r) {}

        double calcularArea() override {
            return 3.14159 * raio;
        }
};

class Triangulo : public Forma {
    private:
        double lado1, lado2, lado3;

    public:
        Triangulo(double la1, double la2, double la3) : Forma("Triangulo"), lado1(la1), lado2(la2), lado3(la3) {}

        double sp = (lado1 + lado2 + lado3) / 2;

        double calcularArea() override {
            return sqrt(sp * (sp - lado1) * (sp - lado2) * (sp - lado3));
        }
};

Forma* criarForma(int tipo, double medida) {
    if(tipo == 1) {
        return new Retangulo(medida, medida);
    } else if(tipo == 2) {
        return new Circulo(medida);
    }
    return new Triangulo(medida, medida, medida);
}

int main() {
    std::cout << "----GERANDO FORMA POR MEIO DE CÓDIGO----" << std::endl;

    Forma *t1 = criarForma(3, 4);

    t1->exibir();

    delete t1;

    return 0;
}
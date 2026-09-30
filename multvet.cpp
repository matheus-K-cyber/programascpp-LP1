#include <iostream>
#include <string>
#include <cmath>
#include <vector>

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

        double calcularArea() override { return largura * altura; }
};

class Circulo : public Forma {
    private:
        double raio;

    public:
        Circulo(double r) : Forma("Circulo"), raio(r) {}

        double calcularArea() override { return 3.14159 * raio * raio; }
};

class Triangulo : public Forma {
    private:
        double lado;

    public:
        Triangulo(double la) : Forma("Triangulo"), lado(la) {}

        double sp = (lado + lado + lado) / 2;

        double calcularArea() override { return sqrt(sp * (sp - lado) * (sp - lado) * (sp - lado)); }
};

double somarAreas(std::vector<Forma*>& formas) {
    double sum = 0;

    for(size_t i = 0; i < formas.size(); i++) {
        sum += formas[i]->calcularArea();
    }

    return sum;
}

void liberar(std::vector<Forma*>& formas) {
    for(size_t i = 0; i < formas.size(); i++) {
        delete formas[i];
    }
    formas.clear();
}


int main() {
    std::vector<Forma*> formas;

    formas.push_back(new Retangulo(4, 4));
    formas.push_back(new Retangulo(2, 3));
    formas.push_back(new Retangulo(5, 3));
    formas.push_back(new Circulo(3));
    formas.push_back(new Circulo(2));
    formas.push_back(new Circulo(5));
    formas.push_back(new Triangulo(4));
    formas.push_back(new Triangulo(2));

    std::cout << "=== FORMAS DISPONÍVEIS E SUAS ÁREAS ===" << std::endl;

    for(size_t i = 0; i < formas.size(); i++) {
        formas[i]->exibir();
    }

    std::cout << "\n=== SOMATÓRIO DAS ÁREAS ===" << std::endl;

    std::cout << "Total: " << somarAreas(formas) << std::endl; 

    std::cout << "\n=== LIBERANDO FORMAS DA MEMÓRIA ===" << std::endl;

    liberar(formas);

    std::cout << "\nArmazenamento atual do vetor 'formas': " << formas.size() << std::endl;

    return 0;
}
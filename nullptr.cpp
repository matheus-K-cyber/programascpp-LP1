#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class Forma {
    protected:
        std::string nome;

    public:
        Forma(std::string form) : nome(form) {}

        std::string getNome() { return nome; }

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
        Retangulo(std::string n, double l, double a) : Forma(n), largura(l), altura(a) {}

        double calcularArea() override { return largura * altura; }
};

class Circulo : public Forma {
    private:
        double raio;

    public:
        Circulo(std::string n, double r) : Forma(n), raio(r) {}

        double calcularArea() override { return 3.14159 * raio * raio; }
};

class Triangulo : public Forma {
    private:
        double lado;

    public:
        Triangulo(std::string n, double la) : Forma(n), lado(la) {}

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

/*void liberarUm(std::vector<Forma*>& formas, std::string n) {
    for(size_t i = 0; i < formas.size(); i++) {
        if(formas[i]->getNome() == n) {
        delete formas[i];                           // Essa função gerou Segmentation fault (core dumped)
        formas.erase(formas.begin() + 1);
        }
    }
}*/

void liberar(std::vector<Forma*>& formas) {
    for(size_t i = 0; i < formas.size(); i++) {
        delete formas[i];
    }
}

Forma* maiorArea(std::vector<Forma*>& formas) {
    double bigger = 0;
    int bigIndex = 0;

    for(size_t i = 0; i < formas.size(); i++) {
        if(formas.size() == 0) {
            return nullptr;
        } else if(formas[i]->calcularArea() > bigger) {
             bigger = formas[i]->calcularArea();
             bigIndex = i;
        }
    }

    return formas[bigIndex];
}

int main() {
    std::vector<Forma*> formas;

    formas.push_back(new Retangulo("ret1", 4, 4));
    formas.push_back(new Retangulo("ret2", 2, 3));
    formas.push_back(new Retangulo("ret3", 5, 3));
    formas.push_back(new Circulo("c1", 3));
    formas.push_back(new Circulo("c2", 2));
    formas.push_back(new Circulo("c3", 5));
    formas.push_back(new Triangulo("tri1", 4));
    formas.push_back(new Triangulo("tri2", 2));

    std::cout << "=== FORMAS DISPONÍVEIS E SUAS ÁREAS ===" << std::endl;

    for(size_t i = 0; i < formas.size(); i++) {
        formas[i]->exibir();
    }

    std::cout << "\n=== SOMATÓRIO DAS ÁREAS ===" << std::endl;

    std::cout << "Total: " << somarAreas(formas) << std::endl; 

    std::cout << "\n=== FORMA COM MAIOR ÁREA ===" << std::endl;

    Forma *form = maiorArea(formas);

    if(form == nullptr) {
        std::cout << "Vetor vazio..." << std::endl;
    } else {
        std::cout << "A forma " << form->getNome() << " possui a maior área, tamanho: " << form->calcularArea() << "m²" << std::endl;
    }

    std::cout << "\n=== LIBERANDO AS OUTRAS FORMAS DA MEMÓRIA ===" << std::endl;

    liberar(formas);
    formas.clear();

    std::cout << "\nArmazenamento atual do vetor 'formas': " << formas.size() << std::endl;

    return 0;
}
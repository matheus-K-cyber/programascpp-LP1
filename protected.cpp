#include <iostream>

class Veiculo {
    protected:
        std::string marca;
        int ano;

    public:
        Veiculo(std::string m, int n) {
            marca = m;
            ano = n;

            std::cout << "Projeto criado com sucesso!" << std::endl;
        }

        void exibir() {
            std::cout << "Marca: " << marca << " ano: " << ano << std::endl;
        }
};

class Carro : public Veiculo {
    private:
        int portas;

    public:
        Carro(int p, std::string m, int n) : Veiculo(m, n) {
            portas = p;

            std::cout << "O carro da marca " << marca << " está em produção, faltam apenas as portas!" << std::endl;
        }

        void teste() {
            if(portas < 2) {
                std::cout << "ERRO! Número requisitado de portas é insuficiente!" << std::endl;
            } else {
                produza();
            }
        }

        void produza() {
            std::cout << "Carro produzido com sucesso! Marca: " << marca << " " << portas << " portas do ano de "
            << ano << " pronto para vendas!" << std::endl;
        }
};

int main() {
    std::cout << "=====SIMULADOR DE PRODUÇÃO DE VEÍCULOS=====" << std::endl;

    Veiculo vei1("Ronda", 2025);
    vei1.exibir();
    Veiculo vei2("Toyota", 2020);
    vei2.exibir();

    std::cout << "###PRODUÇÃO DO CARRO###" << std::endl;

    Carro car1(2, "Fiat", 1999);
    car1.teste();
    Carro car2(0, "Toyota", 2020);
    car2.teste();

    std::cout << "Simulador de produção de veículos encerrando..." << std::endl;

    return 0;
}
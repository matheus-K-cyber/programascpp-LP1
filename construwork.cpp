#include <iostream>

class Funcionarios {
    public:
        std::string nome;
        float salario;

        static int empregados;

        Funcionarios(std::string n, float sal) {
            nome = n;
            salario = sal;
            empregados++;

            std::cout << nome << " entrando em processo de contratação...\n" << "Salário: R$" << salario << std::endl;
            std::cout << "Número de funcionários(atualmente): " << empregados << std::endl;
            std::cout << "-----" << std::endl;
        }

        ~Funcionarios() {
            empregados--;

            std::cout << "Concluindo o processo de contratação de: " << nome << std::endl;
            std::cout << "Número de processos em andamento: " << empregados << std::endl; 
            std::cout << "-----" << std::endl;
        }

        static void status() {
            std::cout << "Total de processos: " << empregados << std::endl;
        }
};

int Funcionarios::empregados = 0;

int main() {
    std::cout << "Processo de contratação:" << std::endl;
    Funcionarios::status();
    std::cout << "\n";
    
    {
        Funcionarios f1("Ricardo", 1335.55);
        Funcionarios f2("Letícia", 1335.55);
        Funcionarios f3("Isaac", 3000.55);

        Funcionarios::status();

        {
            Funcionarios f4("Matheus", 600.00);
            Funcionarios::status();
        }

        Funcionarios::status();
    }

    std::cout << "Encerrando processos de contratação por hoje, situação atual: " << std::endl;
    Funcionarios::status();
    std::cout << std::endl;

    return 0;
}
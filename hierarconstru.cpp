#include <iostream>

class Pessoa {
    protected:
        std::string nome;
        long int cpf;
        int numero;

    public:
        Pessoa(std::string n, long int c, int num)  {
            nome = n;
            cpf = c;
            numero = num;

            std::cout << "Identidade do(a) " << nome << " criada com sucesso!" << std::endl;
        }

        ~Pessoa() {
            std::cout << "Destruição da identidade do(a) " << nome <<" sendo executada..." << std::endl;
        }

        void exibir() {
            std::cout << "Informações de identidade:\n" << "Nome: " << nome << "\nCPF/RG: " << cpf << "\nNúmero: " << numero 
            << std::endl;
        }
};

class Estudante : public Pessoa {
    protected:
        std::string instituicao;

    public:
        Estudante(std::string n, long int c, int num, std::string inst) : Pessoa(n, c, num) {
            instituicao = inst;

            std::cout << "Estudante " << nome << " cadastrado(a) com sucesso na instituição: " << instituicao << std::endl;
        }

        ~Estudante() {
            std::cout << "Processo de desligamento do(a) estudante " << nome << " da instituição " << instituicao
            << " concluindo..." << std::endl;
        }

        void exibir() {
            std::cout << "Status de " << nome << "\nCPF/RG: " << cpf << "\nNúmero: " << numero
            << "\nAtivo na instituição: " << instituicao << std::endl;
        }
};

class EstudanteUniversitario : public Estudante {
    protected:
        long int matricula;
        std::string curso;

    public:
        EstudanteUniversitario(std::string n, long int c, int num, std::string inst, long int matr, std::string cur) 
        : Estudante(n, c, num, inst) {
            matricula = matr;
            curso = cur;

            std::cout << "Matrícula do discente " << nome << " realizada com sucesso! Matrícula: " << matricula << std::endl;
        }

        ~EstudanteUniversitario() {
            std::cout << "Discente formado! Processo de desligamento do discente " << nome << " de matricula " << matricula
            << " finalizando..." << std::endl;
        }

        void exibir() {
            std::cout << "Discente: " << nome << "\nMatrícula: " << matricula << "Histórico com a instituição: " 
            << instituicao << "\nCPF/RG: " << cpf << "\nNúmero: " << numero << std::endl;
        }
};

int main() {
    std::cout << "===CADASTROS===" << "\n" << std::endl;

    {
        Pessoa existe1("Peter Parker", 12345678933, 990289221);
        existe1.exibir();
        std::cout << std::endl;

        Pessoa existe2("Mary Jane", 98754321666, 996269726);
        existe2.exibir();
        std::cout << std::endl;

        Estudante aluno("Gino Thomas", 54321678945, 991234567, "IUBM");
        aluno.exibir();
        std::cout << std::endl;

        EstudanteUniversitario discente("Mary Poppes", 3214567899, 991289322, "UFRN", 202610096762, "Biologia");
        discente.exibir();
        std::cout << std::endl;

    }

    std::cout << std::endl;
    std::cout << "===CADASTROS ENCERRADOS===" << std::endl;

    return 0;
}
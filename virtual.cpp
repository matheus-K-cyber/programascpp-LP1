#include <iostream>
#include <cmath>
#include <iomanip>

class ContaBancaria {
    protected:
        double saldo;
        std::string nome;
        int numero;
        long int cpf;

    public:
        ContaBancaria(double sal, std::string n, int num, long int c) : saldo(sal), nome(n), numero(num), cpf(c) {
            std::cout << "Conta nascendo com dono: " << nome << ", número: " << numero << " e CPF: " 
            << cpf << " criada com sucesso!" << "\nSaldo atual: " << saldo << std::endl;
        }

        virtual double calcularRendimento() = 0;
        virtual double calcularTaxa() = 0;

        virtual void exibir() {
            std::cout << "Usuário: " << nome << "\nContato: " << numero << "\nCPF: " << cpf << "\nSaldo: R$" << saldo 
            << std::endl;
            std::cout << "Expectativa de saldo da conta: R$" << std::fixed << std::setprecision(2) << calcularRendimento() << std::endl;
        }

        virtual ~ContaBancaria() {
            std::cout << "Conta bancária do usuário " << nome << " está destruída!" << std::endl;
        }
};

class ContaPoupanca : public ContaBancaria {
    private:
        int meses;

    public:
        ContaPoupanca(double sal, std::string n, int num, long int c, int m) : ContaBancaria(sal, n, num, c) {
            meses = m;
        }

        double calcularRendimento() override {
            return saldo * pow((1 + 0,5), meses);
        }

        double calcularTaxa() override {
            return 0 + 0;
        }

        void exibir() override {
            std::cout << "///CONTA POUPANÇA///" << std::endl;
            ContaBancaria::exibir();
            std::cout << "Fechando os dados..." << std::endl;
        }
};

class ContaCorrente : public ContaBancaria {
    private:
        double renda, taxa;
        int dias;
    
    public:
        ContaCorrente(double sal, std::string n, int num, long int c, double ren, int d, double t)
        : ContaBancaria(sal, n, num, c) {
            dias = d;
            taxa = t;
            renda = ren;
        }

        double calcularRendimento() override {
            return saldo * pow((1 + calcularTaxa()), dias) - saldo;
        }

        double calcularTaxa() override {
            return taxa / 100;
        }

        void exibir() override {
            std::cout << "///CONTA CORRENTE///" << std::endl;
            ContaBancaria::exibir();
            std::cout << "Fechando a conta e dados..." << std::endl;
        }
};

void abra(ContaBancaria *conta) {
    conta->exibir();
    std::cout << std::endl;
}

int main() {
    std::cout << "=====ABRINDO CONTAS TESTES=====" << std::endl;

    ContaPoupanca poupanca1(20.55, "Matheus", 998777543, 12345678912, 6);
    ContaPoupanca poupanca2(30.55, "Kauã", 998111783, 12347652782, 6);
    ContaCorrente corrente1(7000.45, "Isaac", 991567322, 65445678998, 5000.50, 30, 5);
    ContaCorrente corrente2(8000.45, "Thanos", 991888314, 45632139968, 6500.50, 30, 10);

    std::cout << "\n-----INICIANDO FASE DE PROCESSAMENTOS-----" << std::endl;

    abra(&poupanca1);
    abra(&poupanca2);
    abra(&corrente1);
    abra(&corrente2);

    std::cout << "<<<<<ARRAY POLIMORFICO>>>>>" << std::endl;

    ContaBancaria* contas[4];
    contas[0] = &poupanca1;
    contas[1] = &poupanca2;
    contas[2] = &corrente1;
    contas[3] = &corrente2;

    for(int i = 0; i < 4; i++) {
        contas[i]->calcularRendimento();
    }

    return 0;
}
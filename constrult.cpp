#include <iostream>

class ContaBancaria {
    public:
        int numero;
        double saldoI;
        std::string mensagem;

        static int countContas;

        ContaBancaria() {
            numero = 000000000;
            saldoI = 0.0;
            countContas++;

            std::cout << "Conta limpa criada, número de contas disponíveis: " << countContas << std::endl;
        }

        ContaBancaria(int num) {
            numero = num;
            saldoI = 0.0;
            countContas++;

            std::cout << "Nova conta(zerada) criada, número de contas disponíveis: " << countContas << std::endl;
        }

        ContaBancaria(int num, double sal) {
            numero = num;
            saldoI = sal;
            countContas++;

            std::cout << "Nova conta(com saldo) criada, número de contas disponíveis: " << countContas << std::endl;
        }

        static void contas() {
            std::cout << "Total de contas existentes: " << countContas << std::endl;
        }

        void depositar(double depo) {
            saldoI += depo;

            std::cout << "O valor de R$" << depo << " foi depositado em sua conta!" << std::endl;
        }

        void depositar(double depo, std::string m) {
            saldoI += depo;
            mensagem = m;

            std::cout << "O valor de R$" << depo << " foi depositado em sua conta com um recado:\n";
            std::cout << mensagem << std::endl;
        }

        void transfere(double valor, ContaBancaria &c) {
            saldoI -= valor;
            c.depositar(valor);
        }

        ~ContaBancaria() {
            countContas--;

            std::cout << "Conta deletada, contas restantes: " << countContas << std::endl;
            std::cout << "-----\n";
        }

        void exibir() {
                std::cout << "Número: " << numero << std::endl;
                std::cout << "Saldo atual: R$" << saldoI << std::endl;
                std::cout << "-----\n";
        }
};

int ContaBancaria::countContas = 0;

int main() {
    std::cout << "====BANCO VS ABERTO====" << std::endl;

    ContaBancaria::contas();

    {

        ContaBancaria conta1;
        ContaBancaria conta2;
        ContaBancaria conta3(998832154);
        ContaBancaria conta4(996613349);
        ContaBancaria conta5(997721268, 1350.55);

        std::cout << "-----\n";

        conta1.exibir();
        conta2.exibir();
        conta3.exibir();
        conta4.exibir();
        conta5.exibir();

        ContaBancaria::contas();

        conta3.depositar(130.99);
        conta3.exibir();

        conta4.depositar(500.99, "Primeiro salário");
        conta4.exibir();

        conta5.transfere(350.55, conta3);
        conta5.exibir();
        conta3.exibir();
        {
            ContaBancaria conta6(994411571, 6000.55);
            conta6.exibir();

            ContaBancaria::contas();

            conta6.transfere(6000.54, conta3);
            conta6.exibir();
            conta3.exibir();
        }

        ContaBancaria::contas();
        conta3.exibir();

        std::cout << "====BANCO VS FECHANDO====" << std::endl;
    }

    ContaBancaria::contas();
    
    std::cout << "Sistema desligando..." << std::endl;

    return 0;
}
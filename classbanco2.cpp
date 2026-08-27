#include <iostream>

class ContaBancaria {
    public:

        std::string titular;
        int numero;
        double saldoI, saldo, saldoF, depo, sac;

        void depositar(double valor) {
                saldoF += valor;

                std::cout << "O valor de R$" << valor << " foi depositado ao seu saldo bancário." << std::endl;

                depo = valor;
            }

            void sacar(double valor) {
                if(saldo < valor) {
                    std::cout << "Saldo insuficiente!" << std::endl;
                    sac = 0.0;
                } else {
                    saldoF -= valor;

                    std::cout << "R$" << valor << " foi sacado de seu saldo bancário." << std::endl;

                    sac = valor;
                }
            }

            void consultarSaldo() {
                std::cout << "Seu saldo atual é de R$" << saldo << std::endl;
                saldoI = saldo;
                saldoF = saldo;
            }

            void exibirExtrato() {
                std::cout << "Titular: " << titular << std::endl;
                std::cout << "Número: " << numero << std::endl;
                std::cout << "Extrato bancário atual(PIX): " << std::endl;
                std::cout << "Valor inicial do saldo: R$" << saldoI << std::endl;
                std::cout << "+R$" << depo << std::endl;
                if(sac == 0) {
                    std::cout << "Não houve saque nesta conta neste dia!" << std::endl;
                } else {
                std::cout << "-R$" << sac << std::endl;
                }
                std::cout << "Saldo final: R$" << saldoF << std::endl;
            }
};

int main() {
    ContaBancaria conta1, conta2;

    conta1.numero = 990172533;
    conta1.titular = "Matheus";
    conta1.saldo = 200.00;

    conta2.numero = 990285809;
    conta2.titular = "Kauã";
    conta2.saldo = 500.00;

    conta1.consultarSaldo();
    conta1.depositar(50.00);
    conta1.sacar(250.00);
    conta1.exibirExtrato();

    conta2.consultarSaldo();
    conta2.depositar(102.73);
    conta2.sacar(250.00);
    conta2.exibirExtrato();

    return 0;
}
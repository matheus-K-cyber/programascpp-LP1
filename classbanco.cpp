#include <iostream>

class Banco {
    public:
    
        double saldo;

        void depositar(double x) {
            saldo += x;

            std::cout << "O valor de " << x << " foi depositado ao seu saldo bancário." << std::endl;
        }

        void sacar(double x) {
            if(saldo < x) {
                std::cout << "Saldo insuficiente!" << std::endl;
            } else {
                saldo -= x;

                std::cout << x << " foi sacado de seu saldo bancário." << std::endl;
            }
        }

        void consultarSaldo() {
            std::cout << "Seu saldo atual é de " << saldo << std::endl;
        }
};

int main() {
    Banco conta;

    conta.saldo = 200.00;

    conta.depositar(50.00);
    conta.sacar(250.00);
    conta.consultarSaldo();

    return 0;
}
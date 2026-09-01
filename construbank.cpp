#include <iostream>

class ContaBancaria {
    public:

        std::string titular;
        int numero;
        double saldoI;

        ContaBancaria() {
            std::cout << "Conta bancária não identificada!" << std::endl;
            titular = "Inexistente";
            numero = 000000000;
            saldoI = 0.0;
        }

        ContaBancaria(std::string ti, int num) {
            std::cout << "Conta criada com sucesso e com saldo zerado!" << std::endl;
            titular = ti;
            numero = num;
            saldoI = 0.0;
        }

        ContaBancaria(std::string ti, int num, double sal) {
            std::cout << "Conta ativa encontrada!" << std::endl;
            titular = ti;
            numero = num;
            saldoI = sal;
        }

        void exibir() {
                std::cout << "Titular: " << titular << std::endl;
                std::cout << "Número: " << numero << std::endl;
                std::cout << "Saldo atual: R$" << saldoI << std::endl;
                std::cout << "##########################" << std::endl;
        }
};

int main() {
    ContaBancaria conta1;
    ContaBancaria conta2("Matheus", 998832154);
    ContaBancaria conta3("Kauã", 997721268, 1350.55);

    std::cout << "\n";

    conta1.exibir();
    conta2.exibir();
    conta3.exibir();

    return 0;
}
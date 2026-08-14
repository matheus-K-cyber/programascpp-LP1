#include <iostream>

void contador(int limite) {
    if (limite < 0) {
        std::cout << "N não é um inteiro positivo." << std::endl;
    } else if(limite == 0) {
        std::cout << "N é menor que 1" << std::endl;
    } else if(limite == 1) {
        std::cout << "N é igual ao valor mínimo 1" << std::endl;
    } else {
        for (int i = 1; i < limite; i++) {
            std::cout << i << ", ";
        }

        std::cout << limite << "." << std::endl;
    }
}

int main() {
    int limite;

    std::cout << "Digite o valor N: ";
    std::cin >> limite;
    contador(limite);

    return 0;
}
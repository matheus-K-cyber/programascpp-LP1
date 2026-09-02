#include <iostream>

class Trocar {
    public:
        void trocarPorValor(int a, int b) {
            a = 13;
            b = 21;

            std::cout << "'a' e 'b' dentro do método(valor): a = " << a << " b = " << b << std::endl;
        }

        void trocarPorReferencia(int &a, int &b) {
            a = 13;
            b = 21;

            std::cout << "'a' e 'b' dentro do método(referência): a = " << a << " b = " << b << std::endl;
        }
};

int main() {
    Trocar swap;
    int a = 15, b = 25;

    std::cout << "'a' e 'b' antes da troca(valor): a = " << a << " b = " << b << std::endl;
    swap.trocarPorValor(a, b);
    std::cout << "'a' e 'b' depois da troca(valor): a = " << a << " b = " << b << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "'a' e 'b' antes da troca(referência): a = " << a << " b = " << b << std::endl;
    swap.trocarPorReferencia(a, b);
    std::cout << "'a' e 'b' depois da troca(referência): a = " << a << " b = " << b << std::endl;

    return 0;
}
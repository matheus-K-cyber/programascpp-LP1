#include <iostream>

class Matematica {
    public:
        int multiplicar(int x, int y) {
            std::cout << "Multiplicação de inteiros: ";
            return x * y;
        }

        double multiplicar(double x, double y) {
            std::cout << "Multiplicação de decimais: ";
            return x * y;
        }

        double multiplicar(double x, int y) {
            std::cout << "Multiplicação de inteiro com decimal: ";
            return x * y;
        }

        int multiplicar(int x, int y, int z) {
            std::cout << "Multiplicação de inteiros: ";
            return x * y * z;
        }
};

int main() {
    Matematica mult;

    std::cout << mult.multiplicar(10, 30) << std::endl;
    std::cout << mult.multiplicar(3.4, 5.5) << std::endl;
    std::cout << mult.multiplicar(12.3, 13) << std::endl;
    std::cout << mult.multiplicar(10, 30, 5) << std::endl;

    return 0;
}
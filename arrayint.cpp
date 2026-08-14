#include <iostream>
#include <array>

int soma(const std::array<int, 5>& numeros) {
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += numeros[i];
    }

    return sum;
}

int main() {
    std::array<int, 5> numeros;
    int numero;

    std::cout << "Digite os cinco inteiros do array: " << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cin >> numero;
        numeros[i] = numero;
    }

    std::cout << "Array final: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Somatório: " << soma(numeros) << std::endl;

    return 0;
}
#include <iostream>

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int n;

    std::cout << "Forneça um número: ";
    std::cin >> n;
    std::cout << "Fatorial: " << fatorial(n) << std::endl;

    return 0;
}
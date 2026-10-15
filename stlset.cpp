#include <iostream>
#include <set>

int main() {
    std::set<int> numeros;

    numeros.insert(10);
    numeros.insert(1);
    numeros.insert(3);
    numeros.insert(6);
    numeros.insert(4);
    numeros.insert(2);
    numeros.insert(9);
    numeros.insert(5);
    numeros.insert(8);
    numeros.insert(7);
    numeros.insert(10);
    numeros.insert(9);

    std::cout << "set de numeros com tamanho " << numeros.size() << ":" << std::endl;
    for(const auto& numero : numeros) {
        std::cout << numero << " ";
    }

    numeros.erase(2);
    numeros.erase(4);
    numeros.erase(6);
    numeros.erase(8);
    numeros.erase(10);

    std::cout << "\nset de numeros(sem pares) com tamanho " << numeros.size() << ":" << std::endl;
    for(const auto& numero : numeros) {
        std::cout << numero << " ";
    }
    std::cout << std::endl;

    return 0;
}
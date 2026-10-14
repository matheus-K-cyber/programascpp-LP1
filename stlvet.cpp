#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> frutaria;

    frutaria.push_back("Maçã");
    frutaria.push_back("Banana");
    frutaria.push_back("Mamão");
    frutaria.push_back("Pera");
    frutaria.push_back("Melancia");

    std::cout << "Frutas atuais:" << std::endl;
    for(size_t i = 0; i < frutaria.size(); i++) {
        std::cout << frutaria[i] << std::endl;
    }

    std::cout << "O vetor 'frutaria' tem tamanho: " << frutaria.size() << std::endl;

    return 0;
}
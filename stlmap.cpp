#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, double> produtos;

    produtos["Filé"] = 35.55;
    produtos["Açucar"] = 15.90;
    produtos["Bolo"] = 70.35;
    produtos["Aspirador de pó"] = 34.99;
    produtos["Óleo"] = 12.99;

    std::cout << "PRODUTOS EM ESTOQUE:" << std::endl;
    for(const auto& par : produtos) {
        std::cout << par.first << " por R$" << par.second << std::endl;
    }

    double valorc = 0;
    std::string caro;

    for(const auto& par : produtos) {
        if(par.second > valorc) {
            caro = par.first;
            valorc = par.second;
        }
    }

    std::cout << "\nO produto mais caro do estoque é: " << caro << " com o preço de R$" << valorc << std::endl;

    return 0;
}
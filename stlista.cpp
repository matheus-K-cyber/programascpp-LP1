#include <iostream>
#include <string>
#include <list>

int main() {
    std::list<std::string> cidades;

    cidades.push_back("Mossoró");
    cidades.push_back("Ceará-Mirim");
    cidades.push_front("Massaranduba");
    cidades.push_front("Massaranduba");
    cidades.push_front("Caicó");

    std::cout << "Lista de cidades(não ordenado):" << std::endl;
    for(const auto& cidade : cidades) {
        std::cout << "-" << cidade << std::endl;
    }

    cidades.sort();

    std::cout << "Lista de cidades(ordenado):" << std::endl;
    for(const auto& cidade : cidades) {
        std::cout << "-" << cidade << std::endl;
    }

    cidades.remove("Massaranduba");

    std::cout << "Lista de cidades(pós remoção das 'Massarandubas'):" << std::endl;
    for(const auto& cidade : cidades) {
        std::cout << "-" << cidade << std::endl;
    }

    return 0;
}
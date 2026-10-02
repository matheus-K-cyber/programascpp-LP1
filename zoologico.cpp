#include "zoologico.h"
#include "leao.h"
#include "papagaio.h"
#include "elefante.h"
#include <iostream>

Zoologico::Zoologico() {}

Zoologico::~Zoologico() {
    std::cout << "Mudança de zoológico" << std::endl;

    for(size_t i = 0; i < animais.size(); i++) {
        delete animais[i];
    }
    animais.clear();
}

Animal* Zoologico::buscar(std::string nome) {
    for(size_t i = 0; i < animais.size(); i++) {
        if(animais[i]->getNome() == nome) {
            return animais[i];
        }
    }

    return nullptr;
}

void Zoologico::adicionar(int tipo, std::string nome, double peso) {
    if(buscar(nome) != nullptr) {
        std::cout << "O " << nome << " já está neste zoológico!" << std::endl;

        return;
    }

    Animal *a;

    if(tipo == 1) {
        a = new Leao(nome, peso);
    } else if(tipo == 2) {
        a = new Papagaio(nome, peso);
    } else if(tipo == 3) {
        a = new Elefante(nome, peso);
    } else {
        std::cout << "ERRO! tipo " << tipo << " não é uma opção do sistema!" << std::endl;

        return;
    }

    animais.push_back(a);
    if(tipo == 1) {
        std::cout << "Ok, " << nome << ", o leão, foi adicionado!" << std::endl;
    } else if(tipo == 2) {
        std::cout << "Ok, " << nome << ", o papagaio, foi adicionado!" << std::endl;
    } else if(tipo == 3) {
        std::cout << "Ok, " << nome << ", o elefante, foi adicionado!" << std::endl;
    }
}

void Zoologico::remover(std::string nome) {
    for(size_t i = 0; i < animais.size(); i++) {
        if(animais[i]->getNome() == nome) {
            std::cout << nome << " foi removido com sucesso do zoológico!" << std::endl;
            delete animais[i];
            animais.erase(animais.begin() + i);

            return;
        }
    }

    std::cout << nome << " não está neste zoológico..." << std::endl;
}

void Zoologico::listar() {
    std::cout << "Há, atualmente, " << animais.size() << " animais no nosso zoológico" << std::endl;
    
    std::cout << "Lista dos animais e suas rações(em quilo):" << std::endl;
    for(size_t i = 0; i < animais.size(); i++) {
        animais[i]->exibir();
    }
}

double Zoologico::racaoTotal() {
    double total = 0;

    for(size_t i = 0; i < animais.size(); i++) {
        total += animais[i]->racaoDiaria();
    }

    return total;
}
#include <iostream>
#include <array>

class Iterador {
    private:
        int ind;
        std::array<int, 5> base = {10, 20, 30, 40, 50};
        
    public:
        Iterador(int i = 0) : ind(i) {
            std::cout << "Índice inicializado em " << ind << std::endl; 
        }

        int getI() { return ind; }

        Iterador operator++() {
            ++ind;

            std::cout << "Valor do índice pré-incremento: " << ind << std::endl;

            return *this;
        }

        Iterador operator++(int) {
            Iterador aux = *this;
            ind++;

            std::cout << "Índice antes do pós-incremento: " << aux.ind << ", valor pós-incremento: " << ind << std::endl;

            return aux;
        }

        int operator*() {
            return base[ind];
        }

        void exibir() {
            std::cout << "valor atual do índice: " << ind << std::endl;
        }
};

int main() {
    Iterador it1;

    std::cout << "Elemento apontado pelo índice atual: " << *it1 << std::endl;

    std::cout << "\n|||TESTE: PRÉ-INCREMENTO|||" << std::endl;

    ++it1;
    it1.exibir();

    std::cout << "Apontamento após o pré-incremento: " << *it1 << std::endl;

    std::cout << "\n|||TESTE: PÓS-INCREMENTO|||" << std::endl;

    Iterador it2 = it1++;

    std::cout << "it1(after): "; 
    it1.exibir();
    std::cout << "it2(before) ";
    it2.exibir();

    std::cout << "Apontamento após o pós-incremento: " << *it1 << std::endl;

    return 0;
}
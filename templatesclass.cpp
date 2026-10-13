#include <iostream>
#include <string>

template <typename T>
class Fila {
    private:
        static const int TAMANHO_MAX = 100;
        T fila[TAMANHO_MAX];
        int corpo, i;

    public:
        Fila() : corpo(-1) {
            std::cout << "Fila criada com sucesso(limite :" << TAMANHO_MAX << ")" << std::endl;
        }

        bool vazia() const {
            return corpo == -1;
        }

        int tamanho() const {
            return corpo + 1;
        }

        bool enfileirar(const T& elemento) {
            if(tamanho() == TAMANHO_MAX) {
                std::cout << "ERRO! a fila está cheia demais para mais um entrar..." << std::endl;

                return false;
            }

            fila[++corpo] = elemento;
            std::cout << elemento << " foi adicionado ao fim da fila!" << std::endl;

            return true;
        }

        bool desenfileirar(T& elemento) {
            if(vazia()) {
                std::cout << "ERRO! não há nada na fila..." << std::endl;

                return false;
            }

            elemento = fila[corpo--];
            std::cout << elemento << " acaba de se removido da fila!" << std::endl;

            return true;
        }

        T frente() const {
            return fila[0];
        }
};

int main() {
    std::cout << "Organizando a fila de inteiros!" << std::endl;

    Fila<int> filaI;

    filaI.enfileirar(1);
    filaI.enfileirar(2);
    filaI.enfileirar(3);
    filaI.enfileirar(4);
    filaI.enfileirar(5);

    std::cout << "Tamanho atual da fila: " << filaI.tamanho() << std::endl;

    int valor;
    filaI.desenfileirar(valor);
    filaI.desenfileirar(valor);

    std::cout << "Organizando a fila de strings!" << std::endl;
    Fila<std::string> filaS;

    filaS.enfileirar("Queijo");
    filaS.enfileirar("Pi");
    filaS.enfileirar("Euler");

    std::string texto;

    std::cout << "Primeiro elemento da fila: " << filaS.frente() << std::endl;

    while(!filaS.vazia()) {
        filaS.desenfileirar(texto);
    }

    return 0;
}
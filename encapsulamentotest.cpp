#include <iostream>

class Produto {
    private:
        std::string nome;
        double preco;
        static int estoque;

    public:
        void adicionar(std::string prod, double price) {
            nome = prod;
            preco = price;
            estoque++;

            std::cout << "O produto " << nome << " de preço R$" << preco << " foi adicionado com sucesso." << std::endl;
            std::cout << "Estoque atual: " << estoque << std::endl;
        }

        void remove() {
            if(estoque > 0) {
                preco = 0;
                estoque--;

                std::cout << "O produto " << nome << " foi removido com sucesso." << std::endl;
                std::cout << "Estoque atual: " << estoque << std::endl;
            } else {
                std::cout << "Não há produtos no estoque..." << std::endl;
            }
        }

        void altera(double Nprice) {
            std::cout << "O preço deste produto foi alterado de " << preco << " para " << Nprice << std::endl;

            preco = Nprice;
        }

        void exibir() {
            if(preco == 0) {
                std::cout << "Este produto não está em estoque!" << std::endl;
            } else if(preco > 0) {
                std::cout << nome << " preço: " << preco << std::endl;
            }
        }

        static void status() {
            std::cout << "O estoque atual está em: " << estoque << std::endl;
        }
};

int Produto::estoque = 0;

int main() {
    Produto::status();

    Produto pro1;
    Produto pro2;
    Produto pro3;
    Produto pro4;

    pro1.adicionar("Macarrão", 12.99);
    pro2.adicionar("Mandioca", 9.99);
    pro3.adicionar("Filé bovino", 23.99);
    pro4.adicionar("Tomate", 15.99);

    pro1.exibir();
    pro2.remove();
    pro2.exibir();
    pro3.altera(29.99);
    pro3.exibir();
    
    Produto::status();

    return 0;
}
#include <iostream>
#include <string>

class Produto {
    public:

        std::string nome, price;
        double preco = 0.0, topo = 0.0, total = 0.0;
        int quantidade = 5;

        std::string exibe() {
            return nome;
        }

        double totalEstoque() {
            return total += preco;
        }

        std::string maisCaro() {
            if(preco > topo) {
                topo = preco;
            }

            return price = Produto::nome;
        }

        double caro() {
            return topo;
        }

        void status(int count) {
            if(count < 4) {
            std::cout << exibe() << ", ";
            } else if(count == 4) {
                std::cout << exibe() << "." << std::endl;
            }
        }
};

int main() {
    Produto produtos[5];
    int count = 0;
    double sum, thePrice;
    std::string must;

    produtos[0].nome = "Manteiga";
    produtos[0].preco = 9.50;

    produtos[1].nome = "Macarrão";
    produtos[1].preco = 11.99;

    produtos[2].nome = "Arroz";
    produtos[2].preco = 10.00;

    produtos[3].nome = "Filé de frango";
    produtos[3].preco = 21.49;

    produtos[4].nome = "Feijão";
    produtos[4].preco = 25.00;

    std::cout << "Status atual: " << std::endl;
    std::cout << "Produtos em estoque: ";

    for(int i = 0; i < 5; i++) {
        produtos[i].status(count);
        sum += produtos[i].totalEstoque();
        must = produtos[i].maisCaro();
        thePrice = produtos[i].caro();
        count++;
    }
    std::cout << "Valor total do estoque = R$" << sum << std::endl;
    std::cout << "Item mais caro do estoque: " << must << ", valendo: R$" << thePrice << std::endl;

    return 0;
}
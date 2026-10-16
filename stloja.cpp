#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
// Observações: usar sobrecarga para que as classes possam ser usadas nos containers
// e possam "usar" seus operadores

// A classe:
class Produto {
    private:
        std::string nome;
        double preco;
        int estoque;

    public:
        Produto() : nome(""), preco(0.0), estoque(0) {}

        Produto(std::string n, double real, int num) : nome(n), preco(real), estoque(num) {}

        std::string getN() const { return nome; }
        double getP() const { return preco; }
        int getE() const { return estoque; }

        bool operator<(const Produto& outro) const {
            return nome < outro.nome;
        }

        bool operator==(const Produto& outro) const {
            return nome == outro.nome;
        }

        void setE(int troca) {
            estoque = troca;
        }

        friend std::istream& operator>>(std::istream& is, Produto& produto);

        void exibir() const {
            std::cout << "| Produto: " << nome << " por R$" << preco <<  " | Estoque: " << estoque << " |" << std::endl;
        }
};

std::istream& operator>>(std::istream& is, Produto& produto) {
    std::cout << "Nome: ";
    std::getline(is, produto.nome);

    std::cout << "Preço: ";
    is >> produto.preco;

    std::cout << "Estoque: ";
    is >> produto.estoque;

    return is;
}

void armazem(std::vector<Produto>& produtos) {
    produtos.push_back(Produto("Arroz integral", 8.99, 20));
    produtos.push_back(Produto("Macarrão", 13.99, 15));
    produtos.push_back(Produto("Massa de lasanha", 11.99, 11));
    produtos.push_back(Produto("Peito de frango", 18.99, 23));
    produtos.push_back(Produto("Contra filé bovino", 27.99, 20));
    produtos.push_back(Produto("Coxas de frango", 16.99, 23));
    produtos.push_back(Produto("Costela suina", 25.55, 19));
    produtos.push_back(Produto("Cenouras", 12.99, 30));
    produtos.push_back(Produto("Tomates", 18.10, 29));
    produtos.push_back(Produto("Maçãs", 10.99, 21));
}

void adicionar_produtos(int n, std::vector<Produto>& produtos) {
    Produto aux;

    for(int i = 0; i < n; i++) {
        std::cin >> aux;
        produtos.push_back(aux);
    }
}

void buscar(std::string name, std::set<std::string>& unicoP) {
    std::cout << "Por favor, forneça o nome do produto..." << std::endl;
        std::cin >> name;

        auto resultado = find(unicoP.begin(), unicoP.end(), name);

        if(resultado != unicoP.end()) {
            std::cout << "O produto " << name << " foi encontrado!" << std::endl;
        } else {
            std::cout << name << " não foi encontrado..." << std::endl;
        }
}

void listagem(std::map<std::string, int>& contador) {
    for(const auto& prod : contador) {
        std::cout << "-Produto: " << prod.first << " quantidade: " << prod.second << std::endl;
    }
}

double sum(std::map<std::string, double>& valores, std::vector<Produto>& produtos) {
    double aux = 0;
    int est;
    size_t i = 0;;

    for(const auto& valo : valores) {
        if(produtos[i].getN() == valo.first) {
            est = produtos[i].getE();
            aux += valo.second * est;
        } else if(i < valores.size()) {
            i++;
        }
    }

    return aux;
}

void registrador(std::list<std::string>& historico, std::map<std::string, int>& auxiliar, std::vector<Produto>& produtos) {
    std::map<std::string, int> compras;
    std::string nome;
    int n, i = 0, comp;

    std::cout << "Caro cliente, quantos produtos você deseja comprar? ";
    std::cin >> n;
    std::cout << "Por favor, forneça o(s) nome(s) do(s) produto(s) que você deseja comprar..." << std::endl;

    while(i < n) {
        std::cin >> nome;
        historico.push_back(nome);

        std::cout << "Quantos? ";
        std::cin >> comp;
        auxiliar[nome] = comp;
        i += comp;
    }
}

int main() {
    std::cout << "|||LOJA STL ABERTA|||" << std::endl;

    char resposta;
    std::string aux;
    //. vector: lista de produtos (classe Produto com nome, preço, estoque)
    std::vector<Produto> produtos;

    armazem(produtos);

    std::cout << "ESTOQUE(armazenado): " << std::endl;
    for(const Produto& comida : produtos) {
        comida.exibir();
    }

    std::cout << "Deseja adicionar mais algum produto? ";
    std::cin >> resposta;
    if(resposta == 's') {
        int quant;

        std::cout << "Quantos produtos deseja adicionar? " << std::endl;
        std::cin >> quant;

        adicionar_produtos(quant, produtos);
    } else if(resposta != 'n') {
        std::cout << "ERRO! comando inválido e ignorado..." << std::endl;
    }

    sort(produtos.begin(), produtos.end());

    std::cout << "ESTOQUE(organizado): " << std::endl;
    for(const Produto& comida : produtos) {
        comida.exibir();
    }

    //. set: categorias únicas de produtos
    std::set<std::string> unicoP;
    for(const Produto& p : produtos) {
        unicoP.insert(p.getN());
    }

    std::cout << "Deseja buscar algum produto específico? ";
    std::cin >> resposta;
    if(resposta == 's') {
        buscar(aux, unicoP);
    } else if(resposta != 'n') {
        std::cout << "ERRO! comando inválido e ignorado..." << std::endl;
    }

    //. map<string, int>: contagem de produtos por categoria
    std::map<std::string, int> contador;

    for(const Produto& uni : produtos) {
        contador[uni.getN()] = uni.getE();
    }

    std::cout << "LISTAGEM DOS PRODUTOS(com n° em estoque)" << std::endl;
    listagem(contador);

    //. map<string, double>: valor total em estoque por categoria
    std::map<std::string, double> valores;

    for(const Produto& val : produtos) {
        valores[val.getN()] = val.getP();
    }

    Produto mul;
    double valorT = sum(valores, produtos);
    std::cout << "Valor total do nosso estoque: R$" << valorT << std::endl;

    //. list: histórico de produtos vendidos
    std::list<std::string> historico;
    std::map<std::string, int> auxiliar;

    std::cout << "ETAPA DE VENDAS(ABERTO)" << std::endl;

    registrador(historico, auxiliar, produtos);

    /*for(size_t i = historico.size(); i < auxiliar.size(); i++) {
        
    }*/
    size_t j = 0, troca;
    for(auto& haux : auxiliar) {
        if(produtos[j].getN() == haux.first) {
            troca = produtos[j].getE();
            troca -= haux.second;
            produtos[j].setE(troca);
        } else if(j < produtos.size()) {
            j++;
        }
    }

    std::cout << "PRODUTOS COMPRADOS:" << std::endl;
    for(const auto& hist : historico) {
        std::cout << "-" << hist << std::endl;
    }

    return 0;
}
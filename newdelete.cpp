#include <iostream>
#include <string>

class Livro {
    private:
        std::string titulo;
        int paginas;

    public:
        Livro(std::string t, int p) : titulo(t), paginas(p) {
            std::cout << "O livro '" << titulo << "' acaba de ser adicionado a coleção." << std::endl;
        }

        ~Livro() {
            std::cout << "O livro " << titulo << " está sendo queimado..." << std::endl; 
        }

        void exibir() {
            std::cout << "O livro " << titulo << " possui " << paginas << " páginas" << std::endl;
        }
};

int main() {
    std::cout << "Livros de pilha:" << std::endl;

    {
        Livro l1("Harry Potter", 529);
        Livro l2("Criaturas Mágicas", 461);

        l1.exibir();
        l2.exibir();
    }

    std::cout << "\nLivros 'new' " << std::endl;

    Livro *lp = new Livro("O Conde de Monte Cristo", 453);
    Livro *ls = new Livro("O Morro Dos Ventos Uivantes", 613);

    lp->exibir();
    ls->exibir();

    std::cout << "Antes dos delets" << std::endl;

    delete ls;
    delete lp;

    std::cout << "Pós delete..." << std::endl;

    return 0;
}
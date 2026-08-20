#include <iostream>
#include <string>

class Livro{
public:
    
    std::string livro, autor;
    int pagina;

    void exibirLivro() {
        std::cout << "Livro: " << livro << " do autor: " << autor << " pagina: " << pagina << std::endl;
    }

};

int main() {
    Livro livro1, livro2, livro3;

    livro1.livro = "O Senhor dos Anéis";
    livro1.autor = "J. R. R. Tolkien";
    livro1.pagina = 123;

    livro2.livro = "As Crônicas de Spiderwick";
    livro2.autor = "Tony DiTerlizzi";
    livro2.pagina = 201;

    livro3.livro = "Harry Potter O Cálice de Fogo";
    livro3.autor = "J. K. Rowling";
    livro3.pagina = 154;

    livro1.exibirLivro();
    livro2.exibirLivro();
    livro3.exibirLivro();
    
    return 0;
}
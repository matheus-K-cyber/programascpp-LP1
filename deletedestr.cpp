#include <iostream>
#include <string>

//Regra prática: se a classe tem algum método virtual , o destrutor também tem que ser.
class Arquivo {
    public:
        virtual ~Arquivo() {
            std::cout << "Com destrutor virtual!" << std::endl;
        }
};

class ArquivoTexto : public Arquivo {
    private:
        char *teste2;

    public:
        ArquivoTexto() {
            teste2 = new char[1000];

            std::cout << "'teste' alocou 1000 char na memória!" << std::endl;
        }

        ~ArquivoTexto() {
            delete[] teste2;

            std::cout << "Herdeira liberou os char..." << std::endl;
        }
};

/*class Arquivo {
    public:
        ~Arquivo() {
            std::cout << "Sem destrutor virtual!" << std::endl;
        }
};

class ArquivoTexto : public Arquivo {
    private:
        char *teste;

    public:
        ArquivoTexto() {
            teste = new char[1000];

            std::cout << "'teste' alocou 1000 char na memória!" << std::endl;
        }

        ~ArquivoTexto() {
            delete[] teste;

            std::cout << "Herdeira liberou os char..." << std::endl;
        }
};*/

int main() {
    /*std::cout << "Teste 1: delete por ponteiro para base sem destrutor virtual!" << std::endl;
    Arquivo *a1 = new ArquivoTexto();
    delete a1;*/

    std::cout << "Teste 2: delete por ponteiro para base com destrutor virtual!" << std::endl;
    Arquivo *a2 = new ArquivoTexto();
    delete a2;

    return 0;
}
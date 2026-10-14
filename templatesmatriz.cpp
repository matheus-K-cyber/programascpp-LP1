#include <iostream>
#include <string>
#include <vector>

template<typename T, typename coluna, typename linha>
class Matriz {
    private:
        std::vector<std::vector<T>> matriz;
        int lin;
        int colu;

    public:
        Matriz(linha l, coluna c) : lin(l), colu(c), matriz(l, std::vector<T>(c)){
            std::cout << "Medidas da matriz estabelecidas... Número de linhas: " << lin
            << " número de colunas: " << colu << std::endl;
        }

       T& operator[](int index) {
            if(index < 0 || index > lin || index > colu) {
                std::cout << "Acesso inválido!" << std::endl;

                static T dummy;
                return dummy;
            }

            return matriz[index];
       }

        void preencher(T n) {
            for(int i = 0; i < lin; i++) {
                for(int j = 0; j < colu; j++) {
                    matriz[i][j] = n;
                }
            }

            std::cout << "Matriz com " << n << std::endl;
        }

        void exibir() const {
            std::cout << "Estado da matriz: " << std::endl;

            for(int i = 0; i < lin; i++) {
                std::cout << "[";
                for(int j = 0; j < colu; j++) {
                    std::cout << matriz[i][j];

                    if(j + 1 < colu) {
                        std::cout << " ";
                    }
                }
                std::cout << "]" << std::endl;
            }
        }
};

int main() {
    std::cout << "TESTE COM MATRIZ(int)" << std::endl;

    Matriz<int, int, int> mat1(3, 3);

    mat1.preencher(9);
    mat1.exibir();

    std::cout << "\nTESTE COM MATRIZ(double)" << std::endl;

    Matriz<double, int, int> mat2(3, 4);

    mat2.preencher(2.71);
    mat2.exibir();

    std::cout << "\nTESTE COM MATRIZ(string)" << std::endl;

    Matriz<std::string, int, int> mat3(4, 4);

    mat3.preencher("Batata");
    mat3.exibir();

    std::cout << "FIM DOS TESTES" << std::endl;

    return 0;
}
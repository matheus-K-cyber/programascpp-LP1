#include <iostream>

class Conexao {
    public:

        std::string nome;
        bool open;

        Conexao(std::string name) {
            nome = name;
            open = true;

            std::cout << "Abrindo conexão com o banco " << nome << "...\nConexão bem-sucedida!" << std::endl;
        }

        ~Conexao() {
            if(open) {
                std::cout << "Processo de desconexão em andamento!" << std::endl;
                open = false;
            }
        }

        void exibir(std::string comands) {
            if(open) {
                std::cout << "Comandos em execução: " << comands << std::endl;
            } else {
                std::cout << "Erro! Não há conexão com algum banco de dados no momento." << std::endl;
            }
        }
};

int main() {
    std::cout << "Iniciano sequência de testes para conexão com bancos de dados!" << std::endl;

    {
        Conexao bancoM("Banco Test");
        bancoM.exibir("Abra a conexão;");
        bancoM.exibir("Ativar sequência de fechamento de conexão;");

        std::cout << "Processo de sequência de desconexão iniciado..." << std::endl;
    }

    std::cout << "Processo de desconexão executado com sucesso!" << std::endl;

    return 0;
}
#include <iostream>

class Instrumentos {
    protected:
        std::string instru;
    
    public:
        Instrumentos(std::string ins) : instru(ins) {
            std::cout << "O instrumento " << instru << " foi criado!" << std::endl;
        }

        virtual void tocar() {
            std::cout << "O " << instru << " será tocado..." << std::endl;
        }

        virtual ~Instrumentos() {
            std::cout << instru << " está sendo destruído..." << std::endl;
        }
};

class Violao : public Instrumentos{
    public:
        Violao(std::string ins) : Instrumentos(ins) {}

        void tocar() override {
            std::cout << instru << " com suas cordas tocadas, faz o som: vrão vrão plim tum" << std::endl;
        }
};

class Piano : public Instrumentos {
    public:
        Piano(std::string ins) : Instrumentos(ins) {}

        void tocar() override {
            std::cout << instru << " com suas teclas tocadas, faz o som: plim plim tlim tlim tlon" << std::endl;
        }
};

class Bateria : public Instrumentos {
    public:
        Bateria(std::string ins) : Instrumentos(ins) {}

        void tocar() override {
            std::cout << instru << " ao tocar, de forma unida, o Bumbo, Caixa, Tons, Surdo e Pratos, produz o som: tum pá um dum tschak"
            << std::endl;
        }
};

void tocarInstrumental(Instrumentos *instrumento) {
    instrumento->tocar();
    std::cout << "-----" << std::endl;
}

int main() {
    std::cout << "=====ETAPA DE DECLARAÇÕES=====" << std::endl;

    Violao violao("Violão");
    Piano piano("Piano");
    Bateria bateria("Bateria");

    std::cout << "\n=====POLIMORFISMO(TESTE)=====" << std::endl;

    tocarInstrumental(&violao);
    tocarInstrumental(&piano);
    tocarInstrumental(&bateria);

    std::cout << "\n=====DESTRUTORES COM ARRAYS=====" << std::endl;

    Instrumentos* instrumentos[3];
    instrumentos[0] = &violao;
    instrumentos[1] = &piano;
    instrumentos[2] = &bateria;

    for(int i = 0; i < 3; i++) {
        instrumentos[i]->tocar();
    }

    return 0;
}
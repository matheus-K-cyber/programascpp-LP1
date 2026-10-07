#include <iostream>
#include <cmath>

class Data {
    private:
        int dia, mes, ano;

    public:
        Data(int d, int m, int a) : dia(d), mes(m), ano(a) {
            std::cout << "Data crida com sucesso!" << std::endl;
        }

        int getD() const { return dia; }
        int getM() const { return mes; }
        int getA() const { return ano; }

        bool operator==(const Data& outro) const {
            return fabs(dia - outro.dia) <= 0;
        }

        bool operator!=(const Data& outro) const {
            return !(*this == outro);
        }

        bool operator<(const Data& outro) const {
            return ano < outro.ano;
        }
        
        bool operator>(const Data& outro) const {
            return mes > outro.mes;
        }

        bool operator<=(const Data& outro) const {
            return dia <= outro.dia;
        }

        bool operator>=(const Data& outro) const {
            return mes >= outro.mes;
        }

        void exibir() const {
            std::cout << "Data salva: " << dia << "/" << mes << "/" << ano << std::endl;
        }
};

int main() {
    Data d1(12, 12, 2012);
    Data d2(6, 10, 2026);
    Data d3(25, 12, 2026);
    Data drepet(12, 12, 2012);

    d1.exibir();
    d2.exibir();
    d3.exibir();
    drepet.exibir();

    std::cout << "\n///TESTANDO COMPARADORES SOBRECARREGADOS///" << std::endl;

    if(d1 == drepet) {
        std::cout << "d1 e drepet tem a mesma data: " << d1.getD() << "/" << d1.getM() << "/" << d1.getA() << std::endl;
    }

    if(d1 != d2) {
        std::cout << "d1 e d2 são datas diferentes!" << std::endl;
    }

    if(d1 < d2) {
        std::cout << "d2 está mais atual do que d1" << std::endl;
    }

    if(d3 > d2) {
        std::cout << "d3 está meses a frente de d2" << std::endl;
    }

    if(d2 <= d3) {
        std::cout << "d2 pode se aproximar, em questão de dias, da data d3" << std::endl;
    }

    if(d3 >= d2) {
        std::cout << "d3 e d2 ainda possuem uma distância considerável..." << std::endl;
    }

    return 0;
}
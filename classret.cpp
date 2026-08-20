#include <iostream>
#include <iomanip>
using namespace std;

class Retangulo {
    public:

        float largura, altura;
        
        void calcularArea() {
            cout << "A área do retângulo = " << fixed << setprecision(2) << largura * altura << "m²" << endl;
        }
};

int main() {
    Retangulo retangulo1;

    cout << "Forneça a largura e altura do retângulo\n";
    cin >> retangulo1.largura;
    cin >> retangulo1.altura;

    retangulo1.calcularArea();

    return 0;
}
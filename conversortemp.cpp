#include <iostream>
#include <iomanip>

using namespace std;

float convCforF(float tempe) {
    float convertidoF;

    convertidoF = tempe * 1.8 + 32;

    return convertidoF;
}

float convFforC(float tempe) {
    float convertidoC;

    convertidoC = (tempe - 32) / 1.8;

    return convertidoC;
}

int main() {
    float tempe;
    char escala;

    cout << "Qual valor de temperatura você deseja converter?";
    cin >> tempe;
    cin >> escala;

    if(escala == 'C') {
        cout << "Temperatura em Fahrenheit: " << fixed << setprecision(2) << convCforF(tempe) << endl;
    } else if(escala == 'F') {
        cout << "Temperatura em Celsius: " << fixed << setprecision(2) << convFforC(tempe) << endl;
    } else {
        cout << "Pedido de conversão inválido!" << endl;
    }

    return 0;
}
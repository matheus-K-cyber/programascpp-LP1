#include <iostream>

using namespace std;

bool analistaP(int numero) {
    if (numero <= 1) {
        return false;
    } else {
        for (int i = 2; i * i <= numero; i++) {
            if (numero % i == 0) {
                return false;
            }
        }

        return true;
    }
}

int main() {
    int numero;

    cout << "Digite o inteiro que deseja verificar: ";
    cin >> numero;

    if(analistaP(numero)) {
        cout << numero << " é primo" << endl;
    } else {
        cout << numero << " não é primo" << endl;
    }

    return 0;
}
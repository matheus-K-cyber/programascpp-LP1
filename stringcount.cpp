#include <iostream>
#include <string>

using namespace std;

int medidor(string analise) {
    int tam = 0;

    for(char c : analise) {
        tam++;
    }

    return tam;
}

int main() {
    string analise;

    cout << "Digite uma string que queira conhecer o tamanho(incluso espaços): " << endl;

    getline(cin, analise);

    cout << "A string fornecida possui tamanho: " << medidor(analise) << endl;

    return 0;
}
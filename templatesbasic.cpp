#include <iostream>
#include <string>
#include <array>

template <typename T>
T minimo(T x, T y) {
    std::cout << "Fazendo comparações..." << std::endl;

    return (x < y) ? x : y;
}

template <class T>
void ordenar(T &x, T &y, T &z) {
    T aux;

    std::cout << "Ordenando os parâmetros..." << std::endl;

    if(z < x) {
        aux = x;
        x = z;
        z = aux;
    } 
    
    if(y < x) {
        aux = x;
        x = y;
        y = aux;
    } 
    
    if(z < y && z > x) {
        aux = y;
        y = z;
        z = aux;
    }
}

template <class T, std::size_t N>
void imprimir_array(const std::array<T, N>& x) {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << x[i];
        if (i + 1 < N) std::cout << ", ";
    }
}

int main() {
    std::cout << "|||TEMPLATE(min) COM INTEIROS|||" << std::endl;
    int i1 = 127, i2 = -127;    
    std::cout << "Minímo entre " << i1 << " e " << i2 << ": " << minimo(i1, i2) << std::endl;

    std::cout << "|||TEMPLATE(min) COM FLOATS|||" << std::endl;
    float f1 = 3.14, f2 = 2.71;
    std::cout << "Minímo entre " << f1 << " e " << f2 << ": " << minimo(f1, f2) << std::endl;

    std::cout << "|||TEMPLATE(min) COM STRINGS|||" << std::endl;
    std::string s1 = "Batata", s2 = "Cenoura";
    std::cout << "Minímo entre " << s1 << " e " << s2 << ": " << minimo(s1, s2) << std::endl;

    std::cout << "|||TEMPLATE(ord) COM FLOATS|||" << std::endl;
    float x = 3.14, y = 1.01, z = 2.71;
    std::cout << "Floats antes de serem ordenados: x = " << x << " y = " << y << " z = " << z << std::endl;
    ordenar(x, y, z);
    std::cout << "Floats depois de serem ordenados: x = " << x << " y = " << y << " z = " << z << std::endl;

    std::cout << "|||TEMPLATE(array) COM INTEIROS|||" << std::endl;
    std::array<int, 6> ai = {5, 10, 15, 20, 25, 30};
    imprimir_array(ai);
    std::cout << std::endl;

    std::cout << "|||TEMPLATE(array) COM STRING|||" << std::endl;
    std::array<std::string, 3> as = {"pão", "avião", "machado"};
    imprimir_array(as);
    std::cout << std::endl;

    return 0;
}

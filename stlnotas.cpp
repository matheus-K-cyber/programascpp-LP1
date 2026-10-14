#include <iostream>
#include <vector>

double calcm(std::vector<double>& notas) {
    double aux = 0;

    for(const auto& nota : notas) {
        aux += nota;
    }

    return aux / notas.size();
}

double menor(std::vector<double>& notas) {
    double min = 999999;

    for(const auto& nota : notas) {
        if(nota < min) {
            min = nota;
        }
    }

    return min;
}

double maior(std::vector<double>& notas) {
    double max = 0;

    for(const auto& nota : notas) {
        if(nota > max) {
            max = nota;
        }
    }

    return max;
}

int main() {
    std::vector<double> notas = {9.8, 9.1, 7.4, 6.0, 4.2, 1.0, 0.0, 5.5};

    std::cout << "Média das notas é: " << calcm(notas) << std::endl;

    std::cout << "\nMenor nota: " << menor(notas) << std::endl;

    std::cout << "\nMaior nota: " << maior(notas) << std::endl;

    return 0;
}
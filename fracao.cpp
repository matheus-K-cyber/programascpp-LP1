#include <iostream>

class Fracao {
    private:
        int numerador, denominador;

    public:
        Fracao(int num = 0, int deno = 0) : numerador(num), denominador(deno) {
            std::cout << "Fração " << numerador << "/" << denominador << " criada!" << std::endl;
        }

        int getNum() const { return numerador; }
        int getDeno() const { return denominador; }

        Fracao operator+(const Fracao& outra) const {
            std::cout << "Somando frações:\n";

            if(denominador == outra.denominador) {
                return Fracao(numerador + outra.numerador, denominador);
            } else {
                int numaux = numerador * outra.denominador;
                int outroaux = outra.numerador * denominador;

                return Fracao(numaux + outroaux, denominador * outra.denominador);
            }
        }

        Fracao operator-(const Fracao& outra) const {
            std::cout << "Subtraindo frações:\n";

            if(denominador == outra.denominador) {
                return Fracao(numerador - outra.numerador, denominador);
            } else {
                int Numaux = numerador * outra.denominador;
                int Outroaux = outra.numerador * denominador;

                return Fracao(Numaux - Outroaux, denominador * outra.denominador);
            }
        }

        Fracao operator*(const Fracao& outra) const {
            std::cout << "Multiplicando frações:\n";

            return Fracao(numerador * outra.numerador, denominador * outra.denominador);
        }

        Fracao operator/(const Fracao& outra) const {
            std::cout << "Dividindo frações:\n";

            return Fracao(numerador * outra.denominador, denominador * outra.numerador);
        }

        int divisorc(int num, int deno) {
            int aux = 1;

            for(int i = 2; i <= num && i <= deno; i++) {
                if(num % i == 0 && deno % i == 0) {
                    aux *= i;
                }
            }

            return aux;
        }

        Fracao simplificação(Fracao fra) {
            int mdc = 0;

            if((fra.numerador == 1 && fra.denominador == 1)
                || (fra.numerador == 0 && fra.denominador >= 1)
                || (fra.numerador >= 1 && fra.denominador == 0)) {
                return Fracao(fra.numerador, fra.denominador);
            }

            mdc = divisorc(fra.numerador, fra.denominador);

            return Fracao(fra.numerador / mdc, fra.denominador / mdc);
        }

        void exibir() {
            std::cout << numerador << "/" << denominador << std::endl;
        }
};

int main() {
    Fracao ft(1, 0);
    Fracao f(0, 1);
    Fracao f0(1,1);
    Fracao f1(2, 3);
    Fracao f2(6, 8);
    Fracao f3(10, 3);

    std::cout << std::endl;

    Fracao f4 = f1 + f3;
    std::cout << "f1 + f3 = ";
    f4.exibir();
    std::cout << "Função f4 = ";
    f4.exibir();

    Fracao f5 = f1 - f2;
    std::cout << "f1 - f2 = ";
    f5.exibir();
    std::cout << "Função f5 = ";
    f5.exibir();

    Fracao f6 = f1 * f2;
    std::cout << "f1 * f2 = ";
    f6.exibir();
    std::cout << "Função f6 = ";
    f6.exibir();

    Fracao f7 = f1 / f3;
    std::cout << "f1 / f3 = ";
    f7.exibir();
    std::cout << "Função f7 = ";
    f7.exibir();

    std::cout << std::endl;

    std::cout << "Simplificando f4, f0, f e ft:" << std::endl;
    Fracao f4s = f4.simplificação(f4);
    f4s.exibir();

    f0.simplificação(f0);

    f.simplificação(f);

    ft.simplificação(ft);

    return 0;
}
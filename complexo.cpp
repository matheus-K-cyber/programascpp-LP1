#include <iostream>

class Complexo {
    private:
        int a, b;

    public:
        Complexo(int coma, int comb) : a(coma), b(comb) {}

        int getA() const { return a; }
        int getB() const { return b; }

        friend std::ostream& operator<<(std::ostream& os, const Complexo& complexo);
};

std::ostream& operator<<(std::ostream& os, const Complexo& complexo) {
    if(complexo.b > 0 && complexo.a != 0) {
        os << "\"" << complexo.a << " + " << complexo.b << "i" << "\"";
        
        return os;
    } else if(complexo.b < 0 && complexo.a != 0) {
        os << "\"" << complexo.a << " - " << complexo.b * -1 << "i" << "\"";

        return os;
    } else if(complexo.a == 0 && complexo.b != 0) {
        os << "\"" << complexo.b << "i" << "\"";

        return os;
    } else if(complexo.b == 0 && complexo.a != 0) {
        os << "\"" << complexo.a << "\"";
    }

    return os;
}

int main() {
    Complexo com1(3, 4);
    Complexo com2(3, -14);
    Complexo com3(0, 127);
    Complexo com4(-127, 0);

    std::cout << "|||TESTANDO SOBRECARGA PARA SAÍDA|||" << std::endl;
    std::cout << com1 << std::endl;
    std::cout << com2 << std::endl;
    std::cout << com3 << std::endl;
    std::cout << com4 << std::endl;

    return 0;
}
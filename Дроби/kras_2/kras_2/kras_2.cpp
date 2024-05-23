#include <iostream>

struct Rational {
    int numerator;
    int denominator;

    Rational(int n, int d) {
        int g = gcd(n, d);
        numerator = n / g;
        denominator = d / g;
    }

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Rational myRational(6, 9);
    std::cout << "Числитель: " << myRational.numerator << std::endl;
    std::cout << "Знаменатель: " << myRational.denominator << std::endl;

    return 0;
}

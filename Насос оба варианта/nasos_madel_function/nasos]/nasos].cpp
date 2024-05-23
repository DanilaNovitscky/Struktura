#include <iostream>
#include <cmath>

double nas_hr(double a);
double nas_hc(double a);
double nas_kr(double a);
double nas_kc(double a);

double nas(double (*h_func)(double), double (*k_func)(double), double h, double k) {
    return h_func(h) * 0.5 * exp(k_func(k));
}

double nas_hr(double a) {
    return a * 12.5;
}

double nas_hc(double a) {
    return a * 10.32;
}

double nas_kr(double a) {
    return exp(a);
}

double nas_kc(double a) {
    return exp(1.2 * a);
}

int main() {
    setlocale(LC_ALL, "Russian");
    double h_arg = 5, k_arg = 1.23;
    std::cout << "Рассчитанный параметр Р для r: " << nas(nas_hr, nas_kr, h_arg, k_arg) << std::endl;
    std::cout << "Рассчитанный параметр Р для c: " << nas(nas_hc, nas_kc, h_arg, k_arg) << std::endl;

    return 0;
}
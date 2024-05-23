#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

// Определение абстрактной функции насоса
using NasFunction = function<double(double)>;

// Определение типа функции для вычисления КПД и H для роторного и центробежного насосов
using EfficiencyFunction = function<double(double)>;

// Функция для моделирования роторного насоса
double rotaryPump(double flowRate) {
    // Пример реализации функции мощности роторного насоса
    return pow(flowRate, 2); // Мощность растет пропорционально квадрату расхода
}

// Функция для моделирования центробежного насоса
double centrifugalPump(double flowRate) {
    // Пример реализации функции мощности центробежного насоса
    return pow(flowRate, 2.5); // Мощность растет более быстро
}

// Функция для вычисления КПД роторного насоса
double efficiencyRotary(double flowRate) {
    // Пример реализации функции КПД роторного насоса
    return 1.0 / (1.0 + 0.1 * flowRate); // КПД уменьшается по мере роста расхода
}

// Функция для вычисления КПД центробежного насоса
double efficiencyCentrifugal(double flowRate) {
    // Пример реализации функции КПД центробежного насоса
    return 1.0 / (1.0 + 0.05 * flowRate); // КПД уменьшается, но не так быстро как у роторного насоса
}

// Функция для вычисления параметров роторного насоса
double Nas_r(double flowRate) {
    return rotaryPump(flowRate) * efficiencyRotary(flowRate);
}

// Функция для вычисления параметров центробежного насоса
double Nas_c(double flowRate) {
    return centrifugalPump(flowRate) * efficiencyCentrifugal(flowRate);
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Ввод значения расхода через консоль
    double flowRate;
    cout << "Введите значение расхода: ";
    cin >> flowRate;

    // Выбор типа насоса в зависимости от переданных функций
    NasFunction nas;

    // Выбор функции для вычисления параметров насоса
    cout << "Выберите тип насоса:" << endl;
    cout << "1. Роторный насос" << endl;
    cout << "2. Центробежный насос" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        nas = Nas_r;
        break;
    case 2:
        nas = Nas_c;
        break;
    default:
        cerr << "Неверный выбор." << endl;
        return 1;
    }

    // Расчет параметров насоса
    double power = nas(flowRate);

    // Вывод результата
    cout << "Мощность насоса: " << power << endl;

    return 0;
}

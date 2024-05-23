#include <iostream>
#include <functional>

using namespace std;

// Функция для деления 1 на f1
auto fun1 = [](int a, int b) {
	return 1.0 / (a + b);
};

// Функция для выбора математической операции
auto fun2 = [](char operation) -> function<double(double, double)> {
	switch (operation) {
	case '+':
		return plus<double>();
	case '-':
		return minus<double>();
	case '*':
		return multiplies<double>();
	case '/':
		return divides<double>();
	default:
		throw invalid_argument("Invalid operation");
	}
};

// Функция для вычисления суммы с использованием fun1, fun2 и fun3
void fun3(function<double(int, int)> f1, function<double(double, double)> f2) {
	int startA, startB, step, n;
	char operation;

	// Ввод параметров с консоли
	cout << "Введите начальное значение a: ";
	cin >> startA;
	cout << "Введите начальное значение b: ";
	cin >> startB;
	cout << "Введите шаг увеличения a и b: ";
	cin >> step;
	cout << "Введите количество слагаемых n: ";
	cin >> n;

	// Вложенная функция для вычисления суммы
	auto fun4 = [&](int startA, int startB, int step, int n) {
		double result = f1(startA, startB);
		for (int i = 1; i < n; ++i) {
			startA += step; // Увеличиваем a на шаг
			startB += step; // Увеличиваем b на шаг
			if (i > 0) {
				cout << " " << operation << " ";
			}
			result = f2(result, f1(startA, startB));
		}

		cout << endl;
		return result;
	};
	char answer;
	cout << "\n\nВыполнить расчет?\n";
	cin >> answer;
	if (answer == 'y') {
		// Вычисляем сумму с использованием fun1, fun2 и fun4
		double result = fun4(startA, startB, step, n);

		// Выводим результат
		cout << "Результат: " << result << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	// Вызов функции fun3 с передачей функции fun1 и fun2
	char operation;
	cout << "Введите операцию (+, -, *, /): ";
	cin >> operation;
	cout << endl;
	fun3(fun1, fun2(operation));

	return 0;
}
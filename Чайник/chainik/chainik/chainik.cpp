#include <iostream>
using namespace std;

class Teapot {
private:
	bool isFilled;
	bool isOnStove;
	bool isGasLit;

public:
	// Конструктор с параметрами, позволяющий инициализировать начальное состояние чайника
	Teapot(bool filled, bool onStove, bool gasLit) : isFilled(filled), isOnStove(onStove), isGasLit(gasLit) {}

	void fillWithWater() {
		cout << "Чайник наполняется водой...\n";
		isFilled = true;
	}

	void placeOnStove() {
		cout << "Чайник ставится на плиту...\n";
		isOnStove = true;
	}

	void lightGas() {
		cout << "Газовая плита зажигается...\n";
		isGasLit = true;
	}

	void waitUntilBoiling() {
		cout << "Ждем, пока вода в чайнике закипит...\n";
		for (int i = 0; i < 3; i++) {
			cout << "Происходит нагрев...\n";
		}
		cout << "Чайник закипел!\n";
	}

	void makeTea() {
		if (!isFilled) {
			fillWithWater();
		}
		if (!isOnStove) {
			placeOnStove();
		}
		if (!isGasLit) {
			lightGas();
		}
		waitUntilBoiling();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Стоит ли чайник с водой уже на плите? (1 - да, 0 - нет): ";
	bool isOnStove;
	cin >> isOnStove;

	// Создаем объект класса Teapot в зависимости от ответа пользователя
	if (isOnStove) {
		// Если чайник уже на плите, создаем объект Teapot с нужными параметрами
		Teapot teapot(true, true, false);
		teapot.makeTea();
	}
	else {
		// Если чайник не на плите, создаем объект Teapot с начальными параметрами
		Teapot teapot(false, false, false);
		teapot.makeTea();
	}

	return 0;
}
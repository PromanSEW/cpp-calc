#include <iostream>
#include "calc.h"

using namespace std;

static int get_option() {
	int option;
	while (true) {
		get_int(option);
		if (option > -1 && option < 4) return option;
		cout << "Введите номер от 0 до 3!\n>";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Меню:\n";
	cout << "1. Простые числа\n";
	cout << "2. Перевод систем счисления\n";
	cout << "3. Решение квадратных уравнений\n";
	cout << "Введите номер операции (0 для выхода):\n>";
	switch (get_option()) {
	case 0: return 0;
	case 1: find_delims(); break;
	case 2: convert(); break;
	case 3: solve_square_eq(); break;
	}
	return 0;
}

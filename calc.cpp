#include <iostream>
#include <list>
#include "calc.h"

using namespace std;

template<class ListType>
inline list<ListType>& operator+=(list<ListType>& l, const ListType el) {
	l.push_back(el);
	return l;
}

bool check_cin() {
	if (cin) return true;
	cout << "Введите целое число!\n";
	cin.clear();
	cin.ignore(SHRT_MAX, '\n');
	return false;
}

/** Является ли число положительным */
static bool check_pos_num(const int num) {
	if (!check_cin()) return false;
	if (num > -1) return true;
	cout << "Число должно быть положительным!\n>";
	return false;
}

static bool check_power(const int power) {
	if (!check_cin()) return false;
	if (power == 0 || power == 2 || power == 8 || power == 10) return true;
	cout << "Основание должно быть равно 2, 10, 16!";
	return false;
}

void get_int(int& n) {
	do cin >> n;
	while (!check_cin());
}

static void get_int(int& n, bool (*check)(const int)) {
	do cin >> n;
	while (!check(n));
}

static void get_coef(int& i, char name) {
	cout << "Введите коэффициент " << name << ":\n>";
	do cin >> i;
	while (!check_cin());
}

static void find_delims(const int num) {
	const string delims_s = "Делители числа ";
	const string simple = "\nЭто число - простое";
	if (num == 1) {
		cout << delims_s << "1: 1" << simple;
		return;
	}
	const int half = num / 2;
	list<int> delims;
	delims += 1;
	for (int i = 2; i <= half; i++) {
		if (num % i == 0) delims += i;
	}
	cout << delims_s << num << ": ";
	for (int delim : delims) {
		cout << delim << ", ";
	}
	cout << num;
	if (delims.size() == 1) cout << simple;
}

static void convert(const int num, const int base) {
	cout << "\n";
}

void find_delims() {
	cout << "Простые числа";
	while (true) {
		cout << "\nВведите число (0 для выхода):\n>";
		int number;
		get_int(number, &check_pos_num);
		if (number == 0) break;
		find_delims(number);
	}
}

void convert() {
	cout << "Перевод систем счисления";
	while (true) {
		cout << "\nВведите основание системы исходного числа (2, 10, 16, или 0 для выхода)\n>";
		int power;
		get_int(power, &check_power);
		if (power == 0) break;
		cout << "\nВведите число:\n>";
		int number;
		get_int(number);
		if (number == 0) break;
		convert(number, power);
	}
}

void solve_square_eq() {
	cout << "Решение квадратного уравнения";
	cout << "\nax + bx^2 + c = 0\n";
	int a, b, c;
	get_coef(a, 'a');
	get_coef(b, 'b');
	get_coef(c, 'c');
	double D = pow(b, 2) - 4.0 * a * c;
	if (D == 0.0) {
		double x = -b / (2.0 * a);
		cout << "x = " << x;
	} else if (D > 0.0) {
		double sqr = sqrt(D);
		double x1 = (-b + sqr) / (2.0 * a);
		double x2 = (-b - sqr) / (2.0 * a);
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	} else {
		cout << "Корней нет";
	}
}

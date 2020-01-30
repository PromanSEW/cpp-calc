#include <iostream>
#include <list>
#include "calc.h"

using namespace std;

template<class ListType>
inline list<ListType>& operator+=(list<ListType>& l, const ListType el) {
	l.push_back(el);
	return l;
}

static const string enter_number = "\nВведите число (0 для выхода):\n>";

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

int get_int() {
	int n;
	do cin >> n;
	while (!check_cin());
	return n;
}

static void find_delims(const int num) {
	const string delims_s = "Делители числа ";
	const string simple = "\nЭто число - простое";
	if (num == 1) {
		cout << delims_s << num << ": 1" << simple;
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

static void get_coef(int& i, char name) {
	cout << "Введите коэффициент " << name << ":\n>";
	do cin >> i;
	while (!check_cin());
}

void find_delims() {
	cout << "Простые числа";
	while (true) {
		cout << enter_number;
		int number;
		do cin >> number;
		while (!check_pos_num(number));
		if (number == 0) break;
		find_delims(number);
	}
}

void convert() {
	cout << "Перевод систем счисления";
	while (true) {
		cout << enter_number;
		int number = get_int();
		if (number == 0) break;
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

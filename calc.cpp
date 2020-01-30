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
	cout << "������� ����� �����!\n";
	cin.clear();
	cin.ignore(SHRT_MAX, '\n');
	return false;
}

/** �������� �� ����� ������������� */
static bool check_pos_num(const int num) {
	if (!check_cin()) return false;
	if (num > -1) return true;
	cout << "����� ������ ���� �������������!\n>";
	return false;
}

static bool check_power(const int power) {
	if (!check_cin()) return false;
	if (power == 0 || power == 2 || power == 8 || power == 10) return true;
	cout << "��������� ������ ���� ����� 2, 10, 16!";
	return false;
}

int get_int() {
	int n;
	do cin >> n;
	while (!check_cin());
	return n;
}

static int get_int(bool (*check)(const int)) {
	int n;
	do cin >> n;
	while (!check(n));
	return n;
}

static void find_delims(const int num) {
	const string delims_s = "�������� ����� ";
	const string simple = "\n��� ����� - �������";
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

static void get_coef(int& i, char name) {
	cout << "������� ����������� " << name << ":\n>";
	do cin >> i;
	while (!check_cin());
}

static void convert(const int num, const int base) {
	cout << "\n";
}

void find_delims() {
	cout << "������� �����";
	while (true) {
		cout << "\n������� ����� (0 ��� ������):\n>";
		int number = get_int(&check_pos_num);
		if (number == 0) break;
		find_delims(number);
	}
}

void convert() {
	cout << "������� ������ ���������";
	while (true) {
		cout << "\n������� ��������� ������� ��������� ����� (2, 10, 16, ��� 0 ��� ������)\n>";
		int base = get_int(&check_power);
		if (base == 0) break;
		cout << "\n������� �����:\n>";
		int number = get_int();
		if (number == 0) break;
		convert(number, base);
	}
}

void solve_square_eq() {
	cout << "������� ����������� ���������";
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
		cout << "������ ���";
	}
}

//#include <iostream>
//#include<Windows.h>
//using namespace std;
//
//class Calculator {
//private:
//	double a;
//	double b;
//	char c;
//	double r;
//public:
//	double getA();
//	double getB();
//	char getC();
//	double getR();
//	void setA(double a0);
//	void setB(double a0);
//	Calculator(double a1, double b1);
//	void vychislenie(char x);
//	void randomInt();
//};
//
//Calculator::Calculator(double a1, double b1) {
//	a = a1;
//	b = b1;
//}
//
//double Calculator::getA() {
//	return a;
//}
//
//double Calculator::getB() {
//	return b;
//}
//
//char Calculator::getC() {
//	return c;
//}
//
//double Calculator::getR() {
//	return r;
//}
//
//void Calculator::setA(double a0) {
//	a = a0;
//}
//
//void Calculator::setB(double b0) {
//	b = b0;
//}
//
//
//void Calculator::vychislenie(char x) {
//	c = x;
//	switch (x) {
//		case '+': {
//			r = a + b;
//			break;
//		}
//		case '-': {
//			r = a + b;
//			break;
//		}
//		case '*': {
//			r = a + b;
//			break;
//		}
//		case '/': {
//			r = a + b;
//			break;
//		}
//		default: {
//			cout << "Арифметческое действие отсутствует.\n";
//			break;
//		}
//	}
//	return;
//}
//
//void Calculator::randomInt() {
//	if (a > b) {
//		b += a;
//		a = b - a;
//		b -= a;
//	}
//	r = ((int)a + rand() % ((int)b - (int)a + 1));
//}
//
//
//int main() {
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//	srand(time(NULL));
//
//	double a1, b1;
//	char x0;
//	bool f;
//
//	do {
//		cout << "Установите английскую раскладку.\nВведите число-операнд1: ";
//		cin >> a1;
//		cout << "Введите арифметический знак-оператор (+-*./): ";
//		cin >> x0;
//		cout << "Введите число-операнд2: ";
//		cin >> b1;
//
//		Calculator k(a1, b1);
//		k.vychislenie(x0);
//		double rez = k.getR();
//
//		cout << k.getA() << ' ' << k.getC() << ' ' << k.getB() << ' ' << " = " << k.getR() << endl;
//		k.randomInt();
//		cout << "Рандомное число от " << (int)k.getA() << " до " << (int)k.getB() << " = " << k.getR() << endl;
//		cout << "Продолжить (Да: 1, Нет: 0): ";
//		cin >> f;
//	} while (f == true);
//
//	system("pause");
//	return 0;
//}
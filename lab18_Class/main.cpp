#include <Windows.h>
#include "main.h"


#define MAXSIZE 50

class Shop {
private:
	const int tradePremium = 20, tax = 12;
	//const int maxSize = 50;
	double profit;

	char name[20] = "NoName";
	bool status = false;
	double expenses = -1, cost = -1;
	int size = 0;
	int salaries[MAXSIZE];

public:
	Shop() {
		cout << "Магазин создан." << endl;
	}

	Shop(const char* name, bool status) {
		setName(name);
		setStatus(status);
		cout << "Магазин создан." << endl;
	}

	~Shop() {
		cout << "Магазин удалён." << endl;
	}


	int getTradePremium() {
		return tradePremium;
	}
	int getTax() {
		return tax;
	}

	double getProfit() {
		return profit;
	}

	char* getName() {
		return name;
	}
	void setName(const char* name) {
		if ((strlen(name) + 1) < 20) {
			strcpy_s(this->name, 20, name);
		}
	}

	void open() {
		this->status = true;
	}
	void close() {
		this->status = false;
	}
	void setStatus(bool status) {
		this->status = status;
	}
	bool getStatus() {
		return status;
	}

	double getExpenses() {
		return expenses;
	}
	void setExpenses(double expenses) {
		if (expenses >= 0) {
			this->expenses = expenses;
		}
	}

	double getCost() {
		return cost;
	}
	void setCost(double cost) {
		if (cost >= 0) {
			this->cost = cost;
		}
	}

	int* getSalaries() {
		int* tArr = new int[size];
		for (int i = 0; i < size; i++) {
			tArr[i] = salaries[i];
		}
		return tArr;
	}
	void setSalaries(int* salar, int size) {
		this->size = size;
		for (int i = 0; i < size; i++) {
			this->salaries[i] = salar[i];
		}
	}


	double calcProfit() {
		if (expenses > -1 && cost > -1) {
			int allSalaries = 0;
			for (int i = 0; i < size; i++) {
				allSalaries += salaries[i];
			}

			profit = (cost * (1 + tradePremium / 100) - expenses - allSalaries) * (1 - (tax / 100));
			return profit;
		}
		return -1;
	}

	void print() {
		cout << "Название: " << name << "\nСостояние: " << (status ? "Открыто" : "Закрыто") << endl;
		if (profit > -1)
			cout << "Прибыль: " << profit << endl;
		if (expenses > -1)
			cout << "Расходы: " << expenses << endl;
		if (cost > -1)
			cout << "Себестоимость товаров: " << cost << endl;
		if (size > 0) {
			cout << "Список зарплат работников: \n";
			for (int i = 0; i < size; i++) {
				cout << "Работник №" << i+1 << ": " << salaries[i] << endl;
			}
		}
	}
};

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int size = 5;
	int* salaries = new int[size] {43, 56, 32, 76, 15};

	Shop shop;
	shop.print();
	cout << endl;

	shop.setName("evroopt");
	shop.open();
	shop.setExpenses(200);
	shop.setCost(500);
	shop.setSalaries(salaries, size);
	shop.calcProfit();
	shop.print();

	cout << endl;


	char name[20];
	bool status;
	cout << "Введите имя: ";
	cin.getline(name, 20);
	cout << "Открыт ли магазин? (1 - да, 0 - нет): ";
	cin >> status;

	Shop shop1 = Shop(name, status);
	shop1.print();
	cout << endl;

	Shop* shop2 = new Shop();
	shop2->setName("magazine");
	shop2->close();
	shop2->setCost(600);
	shop2->print();
	cout << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n";
	shop2->~Shop();
	cout << "__________________________________________________\n";
	shop2->print();
	cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,aaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
	Shop* shop3 = new Shop("name", true);
	shop3->print();
	cout << "\n=======================================\n\n";


	Shop* pShop = &shop;
	Shop** pShop2 = &shop2;
	pShop->print();
	(*pShop2)->print();

	Shop& rShop = shop;
	Shop& rShop2 = *shop2;
	rShop.calcProfit();
	rShop2.calcProfit();

	shop.~Shop();

	system("pause");
	return 0;
}

//#include <iostream>
//#include <Windows.h>
//using namespace std;
//
//int main() {
//
//	SetConsoleOutputCP(65001); // UTF-8
//	SetConsoleCP(65001);
//
//
//	cout << "бла бла бла" << endl;
//
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <Windows.h>

using namespace std;

class Human {
private:
	int age;
	double weight;
	bool sex;
	char name[20];

public:
	Human() {
		cout << "Конструктор по умолчанию создал экземпляр касса Human.\n";
	}

	Human(int a, double w, bool s, char n[]) {
		SetAge(a);
		SetWeight(w);
		SetSex(s);
		SetName(n);
	}

	~Human() {
		cout << "Деструктор класса Human уничтожает объект " << GetName() << endl;
	}


	int GetAge() {
		return age;
	}
	int SetAge(int a) {
		if (a > -1 && a < 150) {
			age = a;
			return age;
		}
		else {
			return -1;
		}
	}

	double GetWeight() {
		return weight;
	}
	double SetWeight(double w) {
		if (w > 0 && w < 1000) {
			weight = w;
			return w;
		}
		else {
			return -1;
		}
	}

	bool GetSex() {
		return sex;
	}
	bool SetSex(bool s) {
		sex = s;
		return sex;
	}

	char* GetName() {
		return name;
	}
	char* SetName(char n[]) {
		if (strlen(n) > 0) {
			strcpy_s(name, strlen(n) + 1, n);
			return name;
		}
		else {
			return name;
		}
	}


	int CelebrateBirthday() {
		int a = GetAge();
		SetAge(++a);
		return GetAge();
	}

	double EatFood(double f) {
		double w = GetWeight();
		SetWeight(w + f * 0.75);
		return GetWeight();
	}

	void Show() {
		cout << GetName() << ": " << GetAge() << " лет, " << GetWeight() << " кг, ";
		if (GetSex() == true) {
			cout << "мужской пол.\n";
		}
		else {
			cout << "женский пол.\n";
		}
	}
};

class Array {
protected:
	int len{ 0 };
	double* val{ nullptr };

public:
	Array() = default;

	Array(int _len) {
		len = _len;
		val = new double[_len];
	}

	Array(const Array& a) = delete;
	Array(Array&& a) { }

	~Array() {
		delete[] val;
	}

	Array& operator=(const Array& rhs);
	Array& operator=(Array&& rhs);

	double& operator[](int i) {
		return val[i];
	}

	const double& operator[](int i) const {
		return val[i];
	}
};

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Human h;
	h.Show();

	char a[] = "Радомир";
	h.SetName(a);
	h.SetAge(56);
	h.SetWeight(60.77);
	h.SetSex(true);
	h.Show();

	h.CelebrateBirthday();
	h.Show();
	h.EatFood(0.23);
	h.Show();

	Human* h0 = new Human();
	if (h0 == NULL) {
		cout << "Ошибка создания экземпляра класса Human. Оперативная память под объект не выделена.\n";
		system("pause");
		return 0;
	}
	h0->Show();

	char b[20];
	cout << "Введите имя человека: ";
	cin.getline(b, 20);
	h0->SetName(b);

	int c;
	cout << "Введите возраст человека (полных лет): ";
	cin >> c;
	h0->SetAge(c);

	int d;
	cout << "Введите вес человека (кг.граммы): ";
	cin >> d;
	h0->SetWeight(d);

	int e;
	cout << "Введите пол человека (0-женский, 1-мужской): ";
	cin >> e;
	h0->SetSex(e);
	h0->Show();


}
//#include <iostream>
//#include <Windows.h>
//
//using namespace std;
//
//class Human {
//private:
//	int age;
//	double weight;
//	bool sex;
//	char name[20];
//
//public:
//	Human() {
//		cout << " онструктор по умолчанию создал экземпл€р касса Human.\n";
//	}
//
//	Human(int a, double w, bool s, char n[]) {
//		SetAge(a);
//		SetWeight(w);
//		SetSex(s);
//		SetName(n);
//	}
//
//	~Human() {
//		cout << "ƒеструктор класса Human уничтожает объект " << GetName() << endl;
//	}
//
//
//	int GetAge() {
//		return age;
//	}
//	int SetAge(int a) {
//		if (a > -1 && a < 150) {
//			age = a;
//			return age;
//		}
//		else {
//			return -1;
//		}
//	}
//
//	double GetWeight() {
//		return weight;
//	}
//	double SetWeight(double w) {
//		if (w > 0 && w < 1000) {
//			weight = w;
//			return w;
//		}
//		else {
//			return -1;
//		}
//	}
//
//	bool GetSex() {
//		return sex;
//	}
//	bool SetSex(bool s) {
//		sex = s;
//		return sex;
//	}
//
//	char* GetName() {
//		return name;
//	}
//	char* SetName(char n[]) {
//		if (strlen(n) > 0) {
//			strcpy_s(name, strlen(n) + 1, n);
//			return name;
//		}
//		else {
//			return name;
//		}
//	}
//
//
//	int CelebrateBirthday() {
//		int a = GetAge();
//		SetAge(++a);
//		return GetAge();
//	}
//
//	double EatFood(double f) {
//		double w = GetWeight();
//		SetWeight(w + f * 0.75);
//		return GetWeight();
//	}
//
//	void Show() {
//		cout << GetName() << ": " << GetAge() << " лет, " << GetWeight() << " кг, ";
//		if (GetSex() == true) {
//			cout << "мужской пол.\n";
//		}
//		else {
//			cout << "женский пол.\n";
//		}
//	}
//};
//
//class Array {
//protected:
//	int len{ 0 };
//	double* val{ nullptr };
//
//public:
//	Array() = default;
//
//	Array(int _len) {
//		len = _len;
//		val = new double[_len];
//	}
//
//	Array(const Array& a) = delete;
//	Array(Array&& a) { }
//
//	~Array() {
//		delete[] val;
//	}
//
//	Array& operator=(const Array& rhs);
//	Array& operator=(Array&& rhs);
//
//	double& operator[](int i) {
//		return val[i];
//	}
//
//	const double& operator[](int i) const {
//		return val[i];
//	}
//};
//
//int main() {
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//
//	Human h;
//	h.Show();
//
//	char a[] = "–адомир";
//	h.SetName(a);
//	h.SetAge(56);
//	h.SetWeight(60.77);
//	h.SetSex(true);
//	h.Show();
//
//	h.CelebrateBirthday();
//	h.Show();
//	h.EatFood(0.23);
//	h.Show();
//
//	Human* h0 = new Human();
//	if (h0 == NULL) {
//		cout << "ќшибка создани€ экземпл€ра класса Human. ќперативна€ пам€ть под объект не выделена.\n";
//		system("pause");
//		return 0;
//	}
//	h0->Show();
//
//	char b[20];
//	cout << "¬ведите им€ человека: ";
//	cin.getline(b, 20);
//	h0->SetName(b);
//
//	int c;
//	cout << "¬ведите возраст человека (полных лет): ";
//	cin >> c;
//	h0->SetAge(c);
//
//	int d;
//	cout << "¬ведите вес человека (кг.граммы): ";
//	cin >> d;
//	h0->SetWeight(d);
//
//	int e;
//	cout << "¬ведите пол человека (0-женский, 1-мужской): ";
//	cin >> e;
//	h0->SetSex(e);
//	h0->Show();
//
//	Human* h1;
//	h1 = new Human();
//	if (h1 == NULL) {
//		cout << "ќшибка создани€ экземпл€ра класса Human. ќперативна€ пам€ть под объект не выделена.\n";
//		system("pause");
//		return 0;
//	}
//	h1->Show();
//
//	cout << "¬ведите им€ человека: ";
//	cin.ignore();
//	cin.getline(b, 20);
//	h1->SetName(b);
//
//	cout << "¬ведите возраст человека (полных лет): ";
//	cin >> c;
//	h1->SetAge(c);
//
//	cout << "¬ведите вес человека (кг.граммы): ";
//	cin >> d;
//	h1->SetWeight(d);
//
//	cout << "¬ведите пол человека (0-женский, 1-мужской): ";
//	cin >> e;
//	h1->SetSex(e);
//	
//	h1->Show();
//	h0->Show();
//
//	char n[] = "‘ранческа";
//	Human h2(12, 34.9, false, n);
//	h2.Show();
//
//	cout << "¬ведите им€ человека: ";
//	cin.ignore();
//	cin.getline(b, 20);
//	cout << "¬ведите возраст человека (полных лет): ";
//	cin >> c;
//	cout << "¬ведите вес человека (кг.граммы): ";
//	cin >> d;
//	cout << "¬ведите пол человека (0-женский, 1-мужской): ";
//	cin >> e;
//
//	Human* h3 = new Human(c, d, e, b);
//	if (h3 == NULL) {
//		cout << "ќшибка создани€ экземпл€ра класса Human. ќперативна€ пам€ть под объект не выделена.\n";
//		system("pause");
//		return 0;
//	}
//	h3->Show();
//
//	typedef void (Human::* method)();
//	method m = &Human::Show;
//	(h.*m)();
//	(h0->*m)();
//
//	typedef int (Human::* function)(int);
//	function m0 = &Human::SetAge;
//	(h2.*m0)(50);
//	(h2.*m)();
//	(h1->*m0)(33);
//	(h1->*m)();
//
//	typedef int (Human::* func)();
//	func m1 = &Human::CelebrateBirthday;
//	(h2.*m1)();
//	(h2.*m)();
//	(h3->*m1)();
//	(h3->*m)();
//
//	system("pause");
//	return 0;
//}
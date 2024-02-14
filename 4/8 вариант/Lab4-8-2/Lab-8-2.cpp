#include <iostream>
#include <math.h>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	double a, b, c, p, s;
	cout << "Введите стороны треугольника:  a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
		p = (a + b + c) / 2;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "Площадь треугольника = " << s << endl;
		return 0;
	
}
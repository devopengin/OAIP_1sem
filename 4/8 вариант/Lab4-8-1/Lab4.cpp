#include <iostream>
#include <iomanip>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, space; space = ' ';
	cout << "Введите символ ";
	cin >> c;
	cout << setw(40) << setfill(space) << space;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(39) << setfill(space) << space;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(40) << setfill(space) << space;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(41) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(37) << setfill(space) << space;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(41) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(41) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(41) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(40) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c;
	cout << setw(1) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(39) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c;
	cout << setw(3) << setfill(space) << space;
	cout << setw(1) << setfill(c) << c << endl;
}
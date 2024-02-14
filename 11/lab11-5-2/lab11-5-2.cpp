#include  <iostream> //подключение библиотек//
#include <Windows.h>
using namespace std; //использование пространства имен//
int main() {
	SetConsoleOutputCP(1251);
	int a, b, l=3,n=0,m=0; //переменные//
	char tmp[33]; //массив//
	cout << "Введите число A: "; cin >> a;
	cout << "Ведите с какой позиции k возьмем биты из числа А: "; cin >> n;
	int maskA = 1;
	_itoa_s(maskA, tmp, 2); //создание маску для числа A//
	maskA = maskA << l; //сдвиг маски A для вычисления 3 битов//
	_itoa_s(maskA, tmp, 2);
	cout << "maskA << l" << " (l = " << l << "): " << tmp << '\n';
	maskA = maskA - 1; //отнимаем 1//
	_itoa_s(maskA, tmp, 2);
	maskA = maskA << n; //сдвигаем маску на нужную нам позицию//
	cout << "maskA << n" << "(n = " << n << "): " << tmp << '\n'; //вывод сдвинутой маски//
	_itoa_s(a, tmp, 2);
	cout << "A: " << tmp << '\n';
	_itoa_s((maskA & a), tmp, 2); //используем битовую операцию и для вычисления 3 битов числа A//
	cout << "maskA & A: " << tmp << '\n'; //вывод//
	_itoa_s((maskA & a) >> n, tmp, 2);
	cout << "Введите число B: "; cin >> b;//ввод числа B//
	cout << "Введите позицию, с которой будут заменены биты битами из числа А: "; cin >> m; //ввод позиции m//
	_itoa_s(b, tmp, 2); //переводим число B в двоичную систему//
	cout << "B: " << tmp << '\n';
	int maskB = 1;
	_itoa_s(maskB, tmp, 2); //создание маски для числа B//
	maskB = maskB << l; //сдвигаем маску B//
	_itoa_s(maskB, tmp, 2);
	cout << "maskB << l: " << tmp << '\n';//вывод//
	maskB -= 1; //отнимаем 1//
	_itoa_s(maskB, tmp, 2);
	maskB = maskB << m; //сдвигаем маску B на позицию m..
	_itoa_s(maskB, tmp, 2);
	maskB = ~maskB; //делаем инверсию маски B//
	_itoa_s(maskB, tmp, 2);
	_itoa_s(maskB & b, tmp, 2); //используем битовую операцию и//
	_itoa_s(((maskA & a) >> n) << m, tmp, 2); //сдвигаем биты числа A на n вправо и m влево//
	cout << "((maskA & a) >> n) << m: " << tmp << '\n';
	_itoa_s((maskB & b) | (((maskA & a) >> n) << m), tmp, 2); //перемещаем биты числа A в число B//
	cout << "(maskB & b) | (((maskA & a) >> n) << m): " << tmp << '\n'; //выводим конечный результат//
}
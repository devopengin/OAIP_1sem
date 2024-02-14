#include <iostream>
using namespace std;
int** search_and_change(int** a, int n, int m) { // функция, которая проверяет наличие во всех строках хотя бы 1 отрицательного элемента, и, если во всех строках есть такой, меняет знаки всех элементов на противоположные
	int s = 0;
	for (int i = 0; i < n; i++) { // проходимся по матрице
		for (int j = 0; j < m; j++) {
			if (a[i][j] < 0) {
				s++;
				break;
			}
		}
	}
	if (s == n) { // проверка условия
		cout << "В каждой строке есть хотя бы 1 отрицательный элемент " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = -a[i][j];
			}
		}
	}
	else {
		cout << "Не в каждой строке есть отрицательный элемент" << endl;
	}
	return a;
}
int main() { // основная функция
	setlocale(LC_ALL, "RUS");
	int n, m;
	cout << "Введите размер матрицы ";
	cin >> n >> m; // считываем размер матрицы
	int** a = new int* [n];
	cout << "Введите элементы матрицы " << endl;
	for (int i = 0; i < n; i++) { // считываем матрицу
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	search_and_change(a, n, m); // вызываем функцию
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

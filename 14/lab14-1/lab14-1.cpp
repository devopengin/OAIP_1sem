#include <iostream>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	const int ROW = 4; //количество строк массива
	const int COL = 4; //количество столбцов массива
	int a[ROW][COL];
	int b[ROW][COL];
	int g=0, h=0, k=0;
	srand(time(NULL));
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			a[i][j] = rand() % (-10 - 10) - 10; //заполн€ем массив а рандомными числами
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			b[i][j] = rand() % 100; //заполн€ем массив b рандомными числами
		}
	}
	cout << "ѕерва€ матрица" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << a[i][j] << " "; //выводим первый массив
		}
		cout << endl;
	}
	cout << "¬тора€ матрица" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << b[i][j] << " "; //выводим второй массив
		}
		cout << endl;
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (a[i][j] < b[i][j]) { //проверка условий больше, меньше либо равно
				g++;
			}
			else if (a[i][j] == b[i][j]) {
				h++;
			}
			else if (a[i][j] > b[i][j]) {
				k++;
			}
		}
	}
	//выводим количество совпадений
	cout << " оличество равных элементов: " << h << endl;
	cout << "количество элементов больших: " << k << endl;
	cout << " оличество элементов меньших: " << g << endl;
}
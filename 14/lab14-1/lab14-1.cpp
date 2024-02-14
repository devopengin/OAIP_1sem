#include <iostream>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	const int ROW = 4; //���������� ����� �������
	const int COL = 4; //���������� �������� �������
	int a[ROW][COL];
	int b[ROW][COL];
	int g=0, h=0, k=0;
	srand(time(NULL));
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			a[i][j] = rand() % (-10 - 10) - 10; //��������� ������ � ���������� �������
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			b[i][j] = rand() % 100; //��������� ������ b ���������� �������
		}
	}
	cout << "������ �������" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << a[i][j] << " "; //������� ������ ������
		}
		cout << endl;
	}
	cout << "������ �������" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << b[i][j] << " "; //������� ������ ������
		}
		cout << endl;
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (a[i][j] < b[i][j]) { //�������� ������� ������, ������ ���� �����
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
	//������� ���������� ����������
	cout << "���������� ������ ���������: " << h << endl;
	cout << "���������� ��������� �������: " << k << endl;
	cout << "���������� ��������� �������: " << g << endl;
}
#include <iostream>
using namespace std;
int** search_and_change(int** a, int n, int m) { // �������, ������� ��������� ������� �� ���� ������� ���� �� 1 �������������� ��������, �, ���� �� ���� ������� ���� �����, ������ ����� ���� ��������� �� ���������������
	int s = 0;
	for (int i = 0; i < n; i++) { // ���������� �� �������
		for (int j = 0; j < m; j++) {
			if (a[i][j] < 0) {
				s++;
				break;
			}
		}
	}
	if (s == n) { // �������� �������
		cout << "� ������ ������ ���� ���� �� 1 ������������� ������� " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = -a[i][j];
			}
		}
	}
	else {
		cout << "�� � ������ ������ ���� ������������� �������" << endl;
	}
	return a;
}
int main() { // �������� �������
	setlocale(LC_ALL, "RUS");
	int n, m;
	cout << "������� ������ ������� ";
	cin >> n >> m; // ��������� ������ �������
	int** a = new int* [n];
	cout << "������� �������� ������� " << endl;
	for (int i = 0; i < n; i++) { // ��������� �������
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	search_and_change(a, n, m); // �������� �������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

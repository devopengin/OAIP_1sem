#include <iostream> 
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	double buf; //����������
	double a[200][200]; //������� ������
	double b[400] = { 0 };
	int k = 0;
	cout << "������� ������ ������� (���������� ����� � ��������)";
	cin >> n; //��������� ������ �������
	for (int i = 0; i < n; i++) { //���������� ���� �� ������� �������
		for (int j = 0; j < n; j++) { //���������� ���� �� �������� �������
			cin >> a[i][j];
			b[k] = a[i][j]; //������������ ������� ������� � ������ b � ������������� ������� k
			k++;
		}
	}
	for (int i = 0; i < k; i++) { //���������� ���� ��� ���������� �������
		for (int j = (k - 1); j >= (i + 1); j--) { // ���������� ���� ��� ���������� ������� � �������� �������.
			if (b[j] < b[j - 1]) { //���� ������� ������� ������ �����������, �� ����������� ���� ����
				buf = b[j];
				b[j] = b[j - 1];
				b[j - 1] = buf; //�������� �������� �������
			}
		}
	}
	k--;
	for (int i = 0; i < n; i++) { //���������� ���� ��� ������ ��������� ������� ���������
		a[i][i] = b[k]; //������� ������� ��������� ���������� �� ��������������� ������� ���������������� ������� � ����������� ������� k
		k--;
	}
	for (int i = 0; i < n; i++) { //���������� ���� ��� ������ ������� �� �����
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

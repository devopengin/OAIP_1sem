#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ������� ��� ���������� ���������� ������� ���������� �������
void Random(int** mass, int m, int n)
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mass[i][j] = rand() % 21 + (-10); 
            cout << mass[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int m, n;
    cout << "������� ���������� �����: ";
    cin >> m;
    cout << "������� ���������� ��������: ";
    cin >> n;
    int count = 0;
    int negative = 0, positive = 0, null = 0;

    int** mass = new int* [m]; // �������� ������ ��� ��������� �� ������ ���������� �������
    for (int i = 0; i < m; i++) {
        if (!(mass[i] = new int[n])) { // �������� ������ ��� ������ ������ ���������� �������
            cout << "������������ ������" << endl;
            return 1;
        }
    }

    Random(mass, m, n); // �������� ������� ��� ���������� ������� ���������� �������

    // ������� ���������� �������������, ������������� � ������� ��������� � �������
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mass[i][j] > 0) {
                positive++;
            }
            if (mass[i][j] < 0) {
                negative++;
            }
            if (mass[i][j] == 0) {
                null++;
            }
        }
    }

    // ����� ����������� �������� �� �����
    cout << "���������� ������������� ���������: " << positive << endl;
    cout << "���������� ������������� ���������: " << negative << endl;
    cout << "���������� ���������, ������ ����: " << null << endl;

    // ������������ ������, ���������� ��� ������
    for (int i = 0; i < m; i++) {
        delete[] mass[i];
    }
    delete[] mass;

    return 0;
}

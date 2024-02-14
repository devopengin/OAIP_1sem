#include <iostream>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int m, n;
    cout << "������� ���������� �����: ";
    cin >> m;
    cout << "������� ���������� ��������: ";
    cin >> n;
    int count = 0;

    int** mass = new int* [n]; //��� ������ �������� ������ ��� ��������� �� ������ ���������� �������.
    for (int i = 0; i < n; i++) {
        if (!(mass[i] = new int[m])) { // ��� ������ �������� ������ ��� ������ ���������� �������
            cout << "������������ ������" << endl;
            return 1;
        }
    }

    srand((unsigned)time(NULL)); // ��� ������ �������������� ��������� ��������� �����

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mass[i][j] = rand() % 10; // ��������� ������ ������� ���������� ������� ��������� ������
            cout << mass[i][j] << ' ';
        }
        cout << endl;
    }
    int s = 0;
    for (int j = 0; j < n; j++) { // ���� �������� �� ������� ������� ���������� �������.
        bool nol = false;
        for (int i = 0; i < m; i++) {
            if (mass[i][j] == 0) { // ��� ������ ���������, ����� �� ������� �������� ����
                nol = true;
                s = i;
                break;
            }
        }
        if (nol) { // ������ ���������, ��� �� ������ ���� � �������
            count++;
        }

    }
    cout << "����� ������� ������� � �����: " << s << endl;
    cout << "���������� �������� c 0: " << count << endl;

    for (int i = 0; i < n; i++) {
        delete[] mass[i]; // ��� ������ ����������� ������, ���������� ��� ������ ���������� �������
    }
    delete[] mass;

    return 0;
}

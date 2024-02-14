#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    using namespace std;
    int ROWS, COLS, neg_elem_line = -1; //����������
    cout << "������� ���������� �����\n"; cin >> ROWS;
    cout << "������� ���������� ��������\n"; cin >> COLS;

    double** a = new double* [ROWS]; //������� ��������� ������ a � ����������� �����, ������ ROWS
    for (int i = 0; i < ROWS; ++i) { //������������� ������ ������ ������� a �������� double ������ COLS
        a[i] = new double[COLS];
    }

    cout << "������� ��������:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) { //��������� �������� ������� �� ����� ������������
            cin >> a[i][j];
        }
    }

    cout << "������ �������:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) { //������� ������ �������
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < ROWS; i++) { //���� ������ ������ � ������������� ���������
        for (int j = 0; j < COLS; j++) {
            if (a[i][j] < 0) {
                neg_elem_line = i;
                break;
            }
        }
        if (neg_elem_line != -1) break;
    }

    if (neg_elem_line != -1) { //����� ������ ������� � ������ � ������������� ��������� �� 2, ���� ����� ������ �������
        for (int j = neg_elem_line, i = 0; i < COLS; i++) {
            a[i][j] /= 2;
        }

        cout << "���������:\n";
        for (int i = 0; i < ROWS; i++) { //������� ���������
            for (int j = 0; j < COLS; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else {
        cout << "����� ��� ������������� ���������\n";
    }

    for (int i = 0; i < ROWS; ++i) {
        delete[] a[i]; //������� �����
    }
    delete[] a;

    return 0;
}

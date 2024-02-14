#include <iostream>

using namespace std;

// ������� ��� �������� � ���������� �������
float** creatematrix(int m, int n) {
    float** arr = new float* [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new float[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "������� ������� [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }

    return arr;
}

// ������� ��� ��������� �������
float** processMatrix(float** arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < 0) {
                cout << "������� ������ � ������������� ���������: " << i + 1 << endl;
                for (int k = 0; k < m; k++) {
                    arr[k][j] /= 2;
                }
            }
        }
    }
    return arr;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int m, n;
    cout << "������� ���������� ����� � �������: ";
    cin >> m;
    cout << "������� ���������� �������� � �������: ";
    cin >> n;

    float** arr = creatematrix(m, n);

    cout << "������ ������: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    *processMatrix(arr, m, n);

    cout << "����� ������: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

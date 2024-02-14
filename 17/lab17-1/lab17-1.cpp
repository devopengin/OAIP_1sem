#include <iostream>

using namespace std;

// Функция для создания и заполнения матрицы
float** creatematrix(int m, int n) {
    float** arr = new float* [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new float[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Введите элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }

    return arr;
}

// Функция для обработки матрицы
float** processMatrix(float** arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < 0) {
                cout << "Найдена строка с отрицательным элементом: " << i + 1 << endl;
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
    cout << "Введите количество строк в матрице: ";
    cin >> m;
    cout << "Введите количество столбцов в матрице: ";
    cin >> n;

    float** arr = creatematrix(m, n);

    cout << "Первый массив: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    *processMatrix(arr, m, n);

    cout << "Новый массив: " << endl;
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

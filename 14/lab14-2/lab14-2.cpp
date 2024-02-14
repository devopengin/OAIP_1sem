#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    using namespace std;
    int ROWS, COLS, neg_elem_line = -1; //переменные
    cout << "¬ведите количество строк\n"; cin >> ROWS;
    cout << "¬ведите количество столбцов\n"; cin >> COLS;

    double** a = new double* [ROWS]; //—оздаем двумерный массив a с количеством строк, равным ROWS
    for (int i = 0; i < ROWS; ++i) { //»ициализируем каждую строку массива a массивом double длиной COLS
        a[i] = new double[COLS];
    }

    cout << "¬ведите элементы:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) { //—читываем элементы матрицы из ввода пользовател€
            cin >> a[i][j];
        }
    }

    cout << "ѕерва€ матрица:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) { //выводим первую матрицу
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < ROWS; i++) { //»щем первую строку с отрицательным элементом
        for (int j = 0; j < COLS; j++) {
            if (a[i][j] < 0) {
                neg_elem_line = i;
                break;
            }
        }
        if (neg_elem_line != -1) break;
    }

    if (neg_elem_line != -1) { //ƒелим каждый элемент в строке с отрицательным элементом на 2, если така€ строка найдена
        for (int j = neg_elem_line, i = 0; i < COLS; i++) {
            a[i][j] /= 2;
        }

        cout << "–езультат:\n";
        for (int i = 0; i < ROWS; i++) { //выводим результат
            for (int j = 0; j < COLS; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else {
        cout << "«десь нет отрицательных элементов\n";
    }

    for (int i = 0; i < ROWS; ++i) {
        delete[] a[i]; //очищаем буфер
    }
    delete[] a;

    return 0;
}

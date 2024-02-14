#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция для заполнения двумерного массива случайными числами
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
    cout << "Введите количество строк: ";
    cin >> m;
    cout << "Введите количество столбцов: ";
    cin >> n;
    int count = 0;
    int negative = 0, positive = 0, null = 0;

    int** mass = new int* [m]; // Выделяем память под указатели на строки двумерного массива
    for (int i = 0; i < m; i++) {
        if (!(mass[i] = new int[n])) { // Выделяем память под каждую строку двумерного массива
            cout << "Недостаточно памяти" << endl;
            return 1;
        }
    }

    Random(mass, m, n); // Вызываем функцию для заполнения массива случайными числами

    // Подсчет количества положительных, отрицательных и нулевых элементов в массиве
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

    // Вывод результатов подсчета на экран
    cout << "Количество положительных элементов: " << positive << endl;
    cout << "Количество отрицательных элементов: " << negative << endl;
    cout << "Количество элементов, равных нулю: " << null << endl;

    // Освобождение памяти, выделенной под массив
    for (int i = 0; i < m; i++) {
        delete[] mass[i];
    }
    delete[] mass;

    return 0;
}

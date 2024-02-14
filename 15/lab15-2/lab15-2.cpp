#include <iostream>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int m, n;
    cout << "Введите количество строк: ";
    cin >> m;
    cout << "Введите количество столбцов: ";
    cin >> n;
    int count = 0;

    int** mass = new int* [n]; //Эта строка выделяет память под указатели на строки двумерного массива.
    for (int i = 0; i < n; i++) {
        if (!(mass[i] = new int[m])) { // Эта строка выделяет память под строку двумерного массива
            cout << "Недостаточно памяти" << endl;
            return 1;
        }
    }

    srand((unsigned)time(NULL)); // Эта строка инициализирует генератор случайных чисел

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mass[i][j] = rand() % 10; // Заполняет каждый элемент двумерного массива случайным числом
            cout << mass[i][j] << ' ';
        }
        cout << endl;
    }
    int s = 0;
    for (int j = 0; j < n; j++) { // Цикл проходит по каждому столбцу двумерного массива.
        bool nol = false;
        for (int i = 0; i < m; i++) {
            if (mass[i][j] == 0) { // Эта строка проверяет, равно ли текущее значение нулю
                nol = true;
                s = i;
                break;
            }
        }
        if (nol) { // Строка проверяет, был ли найден нуль в столбце
            count++;
        }

    }
    cout << "Номер первого столбца с нулем: " << s << endl;
    cout << "Количество столбцов c 0: " << count << endl;

    for (int i = 0; i < n; i++) {
        delete[] mass[i]; // Эта строка освобождает память, выделенную под строку двумерного массива
    }
    delete[] mass;

    return 0;
}

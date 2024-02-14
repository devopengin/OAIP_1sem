#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    double* arr = new double[n]; // создание динамического массива

    // заполнение массива
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент массива: ";
        cin >> *(arr + i);
    }

    int minIndex = 0; // индекс минимального элемента
    double min = arr[0]; // минимальный элемент
    bool foundFirstNegative = false; // флаг для отслеживания первого отрицательного элемента
    double sum = 0; // сумма элементов между первым и вторым отрицательными элементами

    for (int i = 0; i < n; i++) {
        // поиск минимального элемента
        if (*(arr+i) < min) {
            min = *(arr + i);
            minIndex = i;
        }

        // вычисление суммы элементов между первым и вторым отрицательными элементами
        if (*(arr + i) < 0) {
            if (foundFirstNegative) {
                break; // выходим из цикла, если уже найден первый отрицательный элемент
            }
            else {
                foundFirstNegative = true;
            }
        }
        else if (foundFirstNegative) {
            sum += *(arr + i);
        }
    }

    // вывод результатов
    cout << "Номер минимального элемента массива: " << minIndex << endl;
    cout << "Сумма элементов массива, расположенных между первым и вторым отрицательными элементами: " << sum << endl;

    delete[] arr; // освобождение памяти, выделенной для массива

    return 0;
}

#include <stdio.h>
#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Инициализация генератора случайных чисел и локали
    srand(time(0));
    setlocale(LC_ALL, "");

    int a;
    int array[8];
    errno_t errf1, errf2;
    FILE* f = nullptr, * f2 = nullptr;

    // Открытие файла "file1.txt" для записи
    errf1 = fopen_s(&f, "file1.txt", "w");

    // Проверка на успешное открытие файла
    if (errf1 != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }

    // Запись случайных чисел в файл "file1.txt"
    for (a = 0; a < 8; a++)
    {
        fprintf(f, "%d, ", rand() % 10);
    }

    printf("Данные записаны в file1.txt\n");

    // Закрытие файла "file1.txt"
    fclose(f);
    f = nullptr;

    // Повторное открытие файла "file1.txt" для чтения
    errf1 = fopen_s(&f, "file1.txt", "r");

    // Проверка на успешное открытие файла
    if (errf1 != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }

    // Открытие файла "file2.txt" для записи
    errf2 = fopen_s(&f2, "file2.txt ", "w");

    // Проверка на успешное открытие файла
    if (errf2 != 0)
    {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }

    // Чтение данных из файла "file1.txt"
    for (a = 0; a < 8; a++)
    {
        fscanf_s(f, "%d, ", &array[a]);
    }

    // Вывод содержимого файла "file1.txt" на экран
    cout << "Содержимое file1.txt" << endl;
    for (int i = 0; i < 8; i++) {
        cout << array[i] << ", ";
    }

    int arr_size = 8;

    // Запись данных из файла "file1.txt" в файл "file2.txt" в обратном порядке
    cout << endl << endl << "Содержимое file2.txt" << endl;
    for (a = 0; a < arr_size / 2; a++)
    {
        fprintf(f2, "%d, ", array[a]);
        cout << array[a] << ", ";
        fprintf(f2, "%d, ", array[arr_size - a - 1]);
        cout << array[arr_size - a - 1] << ", ";
    }

    // Закрытие обоих файлов
    fclose(f);
    fclose(f2);
    return 0;
}

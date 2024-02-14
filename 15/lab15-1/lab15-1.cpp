#include <iostream>
#include <stdio.h>	
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int* ptr, i, n; // Переменные
    int amount=0;
    int sum=0;
    cout << "Введите количество элементов в массиве";
    cin >> n;

    if (!(ptr = (int*)malloc(n * sizeof(int))))  //выделение памяти и проверка, 
    {	                                   //достаточно ли для нее места
        cout << "Недостаточно памяти";
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        cout << "Введите элементы [" << i + 1 << "]\n";
        cin >> *(ptr + i);
    }
    cout << "Массив: " << endl; // Вводим массив
    for (i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    for (i = 0; i < n; i++) { // Ищем количество элементов больше нуля и их сумму
        if (*(ptr + i) > 0) {
            amount++;
            sum += *(ptr + i);
        }
    }
    cout << "Количество элементов блоьше нуля: " << amount << endl;
    cout << "Сумма элементов больше нуля: " << sum << endl;
    free(ptr);    //освобождение динамической памяти

    return 0;
}

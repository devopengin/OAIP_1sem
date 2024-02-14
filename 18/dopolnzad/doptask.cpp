#include <stdio.h>
#include<iostream>
#include <locale>

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "");
    int a, lenght;
    float array[15];
    char buffer[250];
    char* estr;
    errno_t errf1, errf2;//Тип errno_t возвращает код возникающей при работе с файлом ошибки.
    FILE* f, * f2;//создаём указатели на файлы
    errf1 = fopen_s(&f, "file1.txt", "w");//открываем файл для записи

    if (errf1 != 0)//предусматриваем возможность ошибки

    {
        perror("Невозможно создать файл\n");//Функция perror() выводит эту строку значение глобальной переменной ERRNO с сообщением, указанным в параметре функции.
        return EXIT_FAILURE;
    }
    printf("Введите текст:\n");
    for (a = 0; a < 6; a++)
    {
        gets_s(buffer);//передаем введённую строку в буфер
        fputs(buffer, f); fprintf(f, "\n");//печатаем буфер в файл
    }

    printf("Данные записаны в file1.txt\n");
    fclose(f);//закрываем файл
    errf2 = fopen_s(&f2, "file2.txt", "w");  //Открытие для чтения
    if (errf2 != NULL)
        //Проверка открытия файла
    {
        printf("Ошибка открытия файла\n"); return EXIT_FAILURE;
    }
    errf1 = fopen_s(&f, "file1.txt", "r");  //Открытие для чтения
    if (errf1 != NULL)
        //Проверка открытия файла
    {
        printf("Ошибка открытия файла\n"); return EXIT_FAILURE;
    }
    else
        printf("\nЗапсианы в file2.txt строки:\n");
    for (int i = 0; i < 6; i++) {
        fgets(buffer, sizeof(buffer), f); //Чтение строки файла    
        if (buffer[strlen(buffer) - 2] == 'a') {//если строка кончается символом "a", то записываем ее во второй файл
            fputs(buffer, f2);
            puts(buffer);
        }

    }
    fclose(f);
    fclose(f2);//закрываем файлы, с которыми работали
}

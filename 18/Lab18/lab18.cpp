#include <stdio.h>
#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // ������������� ���������� ��������� ����� � ������
    srand(time(0));
    setlocale(LC_ALL, "");

    int a;
    int array[8];
    errno_t errf1, errf2;
    FILE* f = nullptr, * f2 = nullptr;

    // �������� ����� "file1.txt" ��� ������
    errf1 = fopen_s(&f, "file1.txt", "w");

    // �������� �� �������� �������� �����
    if (errf1 != 0)
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }

    // ������ ��������� ����� � ���� "file1.txt"
    for (a = 0; a < 8; a++)
    {
        fprintf(f, "%d, ", rand() % 10);
    }

    printf("������ �������� � file1.txt\n");

    // �������� ����� "file1.txt"
    fclose(f);
    f = nullptr;

    // ��������� �������� ����� "file1.txt" ��� ������
    errf1 = fopen_s(&f, "file1.txt", "r");

    // �������� �� �������� �������� �����
    if (errf1 != 0)
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }

    // �������� ����� "file2.txt" ��� ������
    errf2 = fopen_s(&f2, "file2.txt ", "w");

    // �������� �� �������� �������� �����
    if (errf2 != 0)
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }

    // ������ ������ �� ����� "file1.txt"
    for (a = 0; a < 8; a++)
    {
        fscanf_s(f, "%d, ", &array[a]);
    }

    // ����� ����������� ����� "file1.txt" �� �����
    cout << "���������� file1.txt" << endl;
    for (int i = 0; i < 8; i++) {
        cout << array[i] << ", ";
    }

    int arr_size = 8;

    // ������ ������ �� ����� "file1.txt" � ���� "file2.txt" � �������� �������
    cout << endl << endl << "���������� file2.txt" << endl;
    for (a = 0; a < arr_size / 2; a++)
    {
        fprintf(f2, "%d, ", array[a]);
        cout << array[a] << ", ";
        fprintf(f2, "%d, ", array[arr_size - a - 1]);
        cout << array[arr_size - a - 1] << ", ";
    }

    // �������� ����� ������
    fclose(f);
    fclose(f2);
    return 0;
}

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
    errno_t errf1, errf2;//��� errno_t ���������� ��� ����������� ��� ������ � ������ ������.
    FILE* f, * f2;//������ ��������� �� �����
    errf1 = fopen_s(&f, "file1.txt", "w");//��������� ���� ��� ������

    if (errf1 != 0)//��������������� ����������� ������

    {
        perror("���������� ������� ����\n");//������� perror() ������� ��� ������ �������� ���������� ���������� ERRNO � ����������, ��������� � ��������� �������.
        return EXIT_FAILURE;
    }
    printf("������� �����:\n");
    for (a = 0; a < 6; a++)
    {
        gets_s(buffer);//�������� �������� ������ � �����
        fputs(buffer, f); fprintf(f, "\n");//�������� ����� � ����
    }

    printf("������ �������� � file1.txt\n");
    fclose(f);//��������� ����
    errf2 = fopen_s(&f2, "file2.txt", "w");  //�������� ��� ������
    if (errf2 != NULL)
        //�������� �������� �����
    {
        printf("������ �������� �����\n"); return EXIT_FAILURE;
    }
    errf1 = fopen_s(&f, "file1.txt", "r");  //�������� ��� ������
    if (errf1 != NULL)
        //�������� �������� �����
    {
        printf("������ �������� �����\n"); return EXIT_FAILURE;
    }
    else
        printf("\n�������� � file2.txt ������:\n");
    for (int i = 0; i < 6; i++) {
        fgets(buffer, sizeof(buffer), f); //������ ������ �����    
        if (buffer[strlen(buffer) - 2] == 'a') {//���� ������ ��������� �������� "a", �� ���������� �� �� ������ ����
            fputs(buffer, f2);
            puts(buffer);
        }

    }
    fclose(f);
    fclose(f2);//��������� �����, � �������� ��������
}

#include <iostream>
#include <stdio.h>	
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int* ptr, i, n; // ����������
    int amount=0;
    int sum=0;
    cout << "������� ���������� ��������� � �������";
    cin >> n;

    if (!(ptr = (int*)malloc(n * sizeof(int))))  //��������� ������ � ��������, 
    {	                                   //���������� �� ��� ��� �����
        cout << "������������ ������";
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        cout << "������� �������� [" << i + 1 << "]\n";
        cin >> *(ptr + i);
    }
    cout << "������: " << endl; // ������ ������
    for (i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    for (i = 0; i < n; i++) { // ���� ���������� ��������� ������ ���� � �� �����
        if (*(ptr + i) > 0) {
            amount++;
            sum += *(ptr + i);
        }
    }
    cout << "���������� ��������� ������ ����: " << amount << endl;
    cout << "����� ��������� ������ ����: " << sum << endl;
    free(ptr);    //������������ ������������ ������

    return 0;
}

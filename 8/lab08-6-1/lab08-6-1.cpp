#include <iostream> //����������� ���������//
using namespace std; //������������� ����������� ������//

int main()
{
    setlocale(LC_ALL, ""); // ���������� ����������� ������
    int a=0, x=0, sum=0; //����������//
    cout << "������� ����� ������������������: " << endl;
    cin >> x;
    for (int i = 0; i < x; i++) //���� ����������� ������� ���, ������� ��������� � ������������������//
    {  
        if (i % 2 == 0) //��������� ������� ��������, ���� ����� ������, �� ��������� �� � �����//
            sum += i;
    }
    cout << sum << endl; //������� ����� ������ ����� �� n ������������������//
    return 0;
}
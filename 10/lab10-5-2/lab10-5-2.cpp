#include <iostream> //����������� ���������//
#include <ctime> 
int main()
{
	setlocale(LC_ALL, "RUS"); //������������� ������//
	using namespace std; //������������� ������������ ����//
	const int N = 1000; //����������//
	int i, sz, rmn = 0, rmx = 99, n = 0; //����������//
	int A[N];//������//
	cout << "������� ������ �������" << endl;
	cin >> sz;
	cout << "������ A: " << endl;
	srand((unsigned)time(NULL)); //����� ����� ���� ������� ����� ������������ ������� srand//
	for (i = 0; i < sz; i++) //���� ���� ���������� ��������� ����� � ��������� �� � ������� A//
	{
		A[i] = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << A[i] << endl;
	}
	int length = sz;
	int m = 0; //������ ����������//
	for (int i = 0; i <= length-2; i++) //���� ����� ����������� ������� ���, ������� ��������� � �������//
	{
		if (A[i] >A[i+1]) //��������� �������, ���� ������� ����� ������ �������� ������
		{
			m++;
		}
	}
	cout << "���������� ��������: " << m << endl; //�����/
}



#include  <iostream> //����������� ���������//
#include <Windows.h>
using namespace std; //������������� ������������ ����//
int main() {
	SetConsoleOutputCP(1251);
	int a, b, l=3,n=0,m=0; //����������//
	char tmp[33]; //������//
	cout << "������� ����� A: "; cin >> a;
	cout << "������ � ����� ������� k ������� ���� �� ����� �: "; cin >> n;
	int maskA = 1;
	_itoa_s(maskA, tmp, 2); //�������� ����� ��� ����� A//
	maskA = maskA << l; //����� ����� A ��� ���������� 3 �����//
	_itoa_s(maskA, tmp, 2);
	cout << "maskA << l" << " (l = " << l << "): " << tmp << '\n';
	maskA = maskA - 1; //�������� 1//
	_itoa_s(maskA, tmp, 2);
	maskA = maskA << n; //�������� ����� �� ������ ��� �������//
	cout << "maskA << n" << "(n = " << n << "): " << tmp << '\n'; //����� ��������� �����//
	_itoa_s(a, tmp, 2);
	cout << "A: " << tmp << '\n';
	_itoa_s((maskA & a), tmp, 2); //���������� ������� �������� � ��� ���������� 3 ����� ����� A//
	cout << "maskA & A: " << tmp << '\n'; //�����//
	_itoa_s((maskA & a) >> n, tmp, 2);
	cout << "������� ����� B: "; cin >> b;//���� ����� B//
	cout << "������� �������, � ������� ����� �������� ���� ������ �� ����� �: "; cin >> m; //���� ������� m//
	_itoa_s(b, tmp, 2); //��������� ����� B � �������� �������//
	cout << "B: " << tmp << '\n';
	int maskB = 1;
	_itoa_s(maskB, tmp, 2); //�������� ����� ��� ����� B//
	maskB = maskB << l; //�������� ����� B//
	_itoa_s(maskB, tmp, 2);
	cout << "maskB << l: " << tmp << '\n';//�����//
	maskB -= 1; //�������� 1//
	_itoa_s(maskB, tmp, 2);
	maskB = maskB << m; //�������� ����� B �� ������� m..
	_itoa_s(maskB, tmp, 2);
	maskB = ~maskB; //������ �������� ����� B//
	_itoa_s(maskB, tmp, 2);
	_itoa_s(maskB & b, tmp, 2); //���������� ������� �������� �//
	_itoa_s(((maskA & a) >> n) << m, tmp, 2); //�������� ���� ����� A �� n ������ � m �����//
	cout << "((maskA & a) >> n) << m: " << tmp << '\n';
	_itoa_s((maskB & b) | (((maskA & a) >> n) << m), tmp, 2); //���������� ���� ����� A � ����� B//
	cout << "(maskB & b) | (((maskA & a) >> n) << m): " << tmp << '\n'; //������� �������� ���������//
}
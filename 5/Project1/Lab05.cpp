#include <iostream> //����������� ����������� ���������//
#include <math.h> //����������� ����������� ���������//
int main() //������� main, ������� ���������� ��������//
{
	setlocale(LC_CTYPE, "Russian"); //������������� ������ ��� ������ ������ �� ������� �����//
	using namespace std; //������������� ������������ ���� std//
	double a, b, k; //���������� ���������� ���� double//
	cout << "������� a = ";
	cin >> a;
	cout << "������� b = ";
	cin >> b;
	cout << "������� k = ";
    cin >> k;

    // ������ �������� ����������, ����� a > b > k
    double x;

    if (a < k) {
        x = a;
        a = k;
        k = x;
    }
    if (b < k) {
        x = b;
        b = k;
        k = x;
    }
    if (a < b) {
        x = a;
        a = b;
        b = x;
    }
    std::cout << "���������� �������� ����������:" << a << ">" << b << ">" << k << std::endl;

    return 0;
}

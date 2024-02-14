#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "������� ���������� ��������� � �������: ";
    cin >> n;

    double* arr = new double[n]; // �������� ������������� �������

    // ���������� �������
    for (int i = 0; i < n; i++) {
        cout << "������� ������� �������: ";
        cin >> *(arr + i);
    }

    int minIndex = 0; // ������ ������������ ��������
    double min = arr[0]; // ����������� �������
    bool foundFirstNegative = false; // ���� ��� ������������ ������� �������������� ��������
    double sum = 0; // ����� ��������� ����� ������ � ������ �������������� ����������

    for (int i = 0; i < n; i++) {
        // ����� ������������ ��������
        if (*(arr+i) < min) {
            min = *(arr + i);
            minIndex = i;
        }

        // ���������� ����� ��������� ����� ������ � ������ �������������� ����������
        if (*(arr + i) < 0) {
            if (foundFirstNegative) {
                break; // ������� �� �����, ���� ��� ������ ������ ������������� �������
            }
            else {
                foundFirstNegative = true;
            }
        }
        else if (foundFirstNegative) {
            sum += *(arr + i);
        }
    }

    // ����� �����������
    cout << "����� ������������ �������� �������: " << minIndex << endl;
    cout << "����� ��������� �������, ������������� ����� ������ � ������ �������������� ����������: " << sum << endl;

    delete[] arr; // ������������ ������, ���������� ��� �������

    return 0;
}

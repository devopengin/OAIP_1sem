#include <iostream> //����������� ���������//
using namespace std; //���������� ������������ ����//

int main() {
    setlocale(LC_ALL, "RUS"); //������������� ������//
    int k, n;
    cout << "������� ������ ������� X: "; //���� ����������� ������� X//
    cin >> k;
    cout << "������� ������ ������� Y: "; //���� ����������� ������� Y//
    cin >> n;

    double X[1000]; //������ ������������ ����������� ��������//
    double Y[1000];
    double z[1000] = { 0 };

    for (int i = 0; i < k; i++) { //������ ������ ������//
        cout << "������� " << i + 1 << " ������� ������� X: ";
        cin >> *(X+i); 
    }
    for (int i = 0; i < n; i++) {//������ ������ ������//
        cout << "������� " << i + 1 << " ������� ������� Y: ";
        cin >> *(Y + i);
    }
 
    int count = 0; //���������� ��� �������� ��������� �����//

    for (int i = 0; i < n; i++)  //���� ����������� ������� ���, ������� ��������� �� ������ �������//
    {
        if (i < k && *(X+i) == *(Y+i)) { //���� ����� � �������� ���������, �� ��������� �� � ������ z/
            *(z+count) = *(Y+i);
            count++;
        }
    }

    cout << "����������� �������� X � Y (������ Z): ";
    if (count > 0) {
        for (int i = 0; i < count; i++) { //������� ����������� ��������//
            cout << *(z + i) << " ";
        }
    }
    else { //�����//
        cout << "����������� ���" << endl;
    }

    return 0;
}


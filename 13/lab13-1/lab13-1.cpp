//#include <iostream>
//#include <string> // подключение библиотеки
//#include <cstring> 
//#include <algorithm>
//using std::string;
//using namespace std;// использование только пространства имен std::string
//
//int main()
//{
//	setlocale(LC_CTYPE, "RUS"); // установка локали
//	char strin1[100] = ""; // первый массив
//	char strin2[100] = ""; // второй массив
//	int x, y;
//	string k;
//	cout << "Строка 1: "; // ввод первой строки
//	cin.getline(strin1, 100); // считывание строки с пробелами
//	cout << strlen(strin1) << endl; // определение длины первой строки
//	x = strlen(strin1);
//	cout << "Введите окончание: " << endl;
//	cin >> k;
//	for (int i = 0; i < strlen(strin1); i++) // проходимся по массиву
//	{
//		if (strin1[i] == k[0]) // сравниваем буквы
//		{
//			cout << "Совпадающий символ: " << strin1[i] << endl; // выводим совпадающие
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    char* end;
    cout << "Задайте последовательность из 3 слов" << endl;
    string str1 = "";
    string str2 = "";
    string str3 = "";

    cin >> str1 >> str2 >> str3;
    cout << "Введите окончание" << endl;
    
    cin >> *end;

    if (str1[str1.size() - 1] == *end) {
        cout << str1 << endl;
    }
    if (str2[str2.size() - 1] == *end) {
        cout << str2 << endl;
    }
    if (str3[str3.size() - 1] == *end) {
        cout << str3 << endl;
    }

    return 0;
}


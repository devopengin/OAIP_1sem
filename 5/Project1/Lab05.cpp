#include <iostream> //подключение необходимых библиотек//
#include <math.h> //подключение необходимых библиотек//
int main() //функци€ main, котора€ возвращает значение//
{
	setlocale(LC_CTYPE, "Russian"); //устанавливает локаль дл€ вывода текста на русском €зыке//
	using namespace std; //использование пространства имен std//
	double a, b, k; //объ€вление переменных типа double//
	cout << "¬ведите a = ";
	cin >> a;
	cout << "¬ведите b = ";
	cin >> b;
	cout << "¬ведите k = ";
    cin >> k;

    // ћен€ем значени€ переменных, чтобы a > b > k
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
    std::cout << "»змененные значени€ переменных:" << a << ">" << b << ">" << k << std::endl;

    return 0;
}

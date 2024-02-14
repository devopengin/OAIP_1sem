#include <iostream> //подключение библиотек//
#include <ctime> 
int main()
{
	setlocale(LC_ALL, "RUS"); //устанавливаем локаль//
	using namespace std; //использование пространства имен//
	const int N = 1000; //переменные//
	int i, sz, rmn = 0, rmx = 99, n = 0; //переменные//
	int A[N];//массив//
	cout << "¬ведите размер массива" << endl;
	cin >> sz;
	cout << "ћассив A: " << endl;
	srand((unsigned)time(NULL)); //„тобы числа были разными нужно использовать функцию srand//
	for (i = 0; i < sz; i++) //Ётот цикл генерирует случайные числа и сохран€ет их в массиве A//
	{
		A[i] = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << A[i] << endl;
	}
	int length = sz;
	int m = 0; //вводим переменную//
	for (int i = 0; i <= length-2; i++) //цикл будет выполн€тьс€ столько раз, сколько элементов в массиве//
	{
		if (A[i] >A[i+1]) //провер€ем условие, если элемент слева больше элемента справа
		{
			m++;
		}
	}
	cout << " оличество инверсий: " << m << endl; //вывод/
}



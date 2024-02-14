#include <iostream> //подключение библиотек
#include <string>
using namespace std; //использование пространства имен

int main()
{
	string str[9] = { "Peace", " world", " dolor", " car", " world", " ipsum", " plabe", " sit" }; //массив
	for (int i = 0; i < 8; i++)
	{
		cout << str[i] << endl; //вывод массива
	}
	for (int i = 7; i >= 0; i--) //используется вложенный цикл for, чтобы проверить каждый элемент массива str на наличие повторений
	{
		for (int k = 0; k < i; k++)
		{
			if (str[i] == str[k])
				str[k].erase(); //Если найдено повторение, используется функция erase, чтобы удалить повторяющийся элемент
		}
	}


	for (int i = 0; i < 9; i++) //После удаления повторяющихся элементов, используется еще один цикл for, чтобы вывести обновленный массив str на экран
	{
		for (int k = 0; k < str[i].size(); k++)
		{
			cout << str[i][k];
		}
	}
	return 0;
}
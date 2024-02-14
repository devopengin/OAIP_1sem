#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	char str[200];
	int counter = 0, result = 0, index = 1, counter_of_spaces = 1;

	cout << "Введите строку: ";
	cin.getline(str, sizeof(str));

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i + 1] == '\0') {
			if (++counter < result) {
				result = counter;
				index = counter_of_spaces;
			}
		}
		else if (str[i] == ' ') {
			if (counter < result) {
				index = counter_of_spaces;
				result = counter;
			}
			result = (result == 0) ? counter : result;
			counter = 0;
			counter_of_spaces++;
		}
		else {
			counter++;
		}
	}

	cout << "Минимальная длина слова: " << result << endl;
	cout << "Номер этого слова: " << index;

	return 0;
}
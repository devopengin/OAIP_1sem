#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	FILE* mf;
	errno_t err;
	err = fopen_s(&mf, "file1.txt", "r");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	fseek(mf, 0, 2);
	int fsize = ftell(mf);
	fseek(mf, 0, 0);
	FILE* mf1;
	char* arr;
	arr = new char[fsize];
	err = fopen_s(&mf1, "file2.txt", "a");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	char estr, estr1;
	for (int i = 0; i < fsize; i + 2) {
		/*fseek(mf, i, 0);
		fscanf(mf, "%c", 1);
		fprintf(mf1, "%c", 1);
		fseek(mf, i, 2);
		fscanf(mf, "%c", 1);
		fprintf(mf1, "%c", 1);*/
		fseek(mf, i, 0);
		estr=fread(arr, sizeof(char), 1, mf);
		//if (estr == NULL) {       //Конец файла или ошибка чтения?
		//	if (feof(mf) != 0)
		//		printf("\nЧтение файла закончено\n");
		//	else
		//	{
		//		printf("\nОшибка чтения из файла\n");
		//		return -1;
		//	}
		}
		fwrite(arr, sizeof(char), 1, mf1);
		fseek(mf, i+1, 2);
		fread(arr, sizeof(char), 1, mf);
		estr1 = fread(arr, sizeof(char), 1, mf);
		//if (estr == NULL) {       //Конец файла или ошибка чтения?
		//	if (feof(mf) != 0)
		//		printf("\nЧтение файла закончено\n");
		//	else
		//	{
		//		printf("\nОшибка чтения из файла\n");
		//		return -1;
		//	}
		//}
		fwrite(arr, sizeof(char), 1, mf1);
	}
	cout << arr << endl;
	fclose(mf);
	fclose(mf1);
}

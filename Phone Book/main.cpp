#include <iostream>
#include "PhoneBook.h"
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;


int main()
{
	int option = 0; //переменная выбора пользователя
	int size = 0;
	Contact* phonebook = new Contact[size]; //массив сотрудников, размер которого будет менятся в ходе програмы
	char list[] = "phonebook.txt"; //название текстового документа в который будут записываться изменения массива
	ClearFileContents(list); //очищение файла после предыдущей работы программы
	//цикл основной работы программы
	do
	{
		system("cls");
		ShowMenu();
		cout << " Enter your option: ";
		cin >> option;
		PerformAction(option, phonebook, size, list);
	} while (option != 0);

	delete[] phonebook;
	return 0;
}
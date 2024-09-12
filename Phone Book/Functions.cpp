#include <iostream>
#include <windows.h>
#include "PhoneBook.h"
#pragma warning(disable : 4996)
using namespace std;

//ф-ия очищения текстового файла путем открытия и закрытия его
void ClearFileContents(char filename[])
{
	FILE* file = fopen("phonebook.txt", "w");
	if (file != nullptr)
	{
		fclose(file);
	}
	else
	{
		cout << "Error: Unable to open file." << endl;
	}
}
//ф-ия что выводит меню на экран
void ShowMenu()
{
	cout << " 1. Show all contacts " << endl << " 2. Search by full name " << endl << " 3. Add new contact " << endl << " 4. Delete contact " << endl << " 0. Exit " << endl;
}
//ф-ия что записывает массив контактов в файл
void WriteContactToFile(const Contact* list, int& size)
{
	FILE* file = fopen("phonebook.txt", "a");
	if (file != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(file, "%s ", list[i].GetName());
			//fprintf(file, " %s ", list[i].surname);
			//fprintf(file, " %s ", list[i].second_name);
			//fprintf(file, " %d ", list[i].home_);
			fputc('\n\n', file);
		}
		fclose(file);
	}
	else {
		cout << "Error: Unable to open file for writing." << endl;
	}
}
//ф-ия что считывает с файла данные и выводит на экран
void ViewContactsFromFile()
{
	FILE* file = fopen("phonebook.txt", "r");
	if (file != nullptr)
	{
		char name[50], surname[50], s_surname[50], h_phone[50], w_phone[50], m_phone[50], a_info[50];
		while (fscanf(file, "%49s %49s %49s %49s %49s %49s %49s", name, surname, s_surname, h_phone, w_phone, m_phone, a_info) == 7)
		{
			cout << name << " " << surname << " " << s_surname << endl;
			cout << a_info << endl;
			cout << "Home phone: " << h_phone << endl;
			cout << "Work phone: " << w_phone << endl;
			cout << "Mobile phone: " << m_phone << endl << endl;
		}
		fclose(file);
	}
	else
	{
		cout << "Error: Unable to open file for reading." << endl;
	}
}
//ф-ия которая вызывает другие ф-ии согласно выбору в меню пользователя
void PerformAction(int option, Contact* list, int& size, char filename[])
{
	if (option == 1) ViewContactsFromFile();
	//else if (option == 2) SearchByName(list, size);
	//else if (option == 3) AddContact(list, size, filename);
	//else if (option == 4) DeleteContact(list, size, filename);
	else if (option == 0) exit(0);

	char temp;
	cout << endl << "Enter smth to continue...";
	cin >> temp;
}

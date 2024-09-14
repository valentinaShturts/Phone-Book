#include <iostream>
#include "PhoneBook.h"
#include <windows.h>
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
			fprintf(file, " %s ", list[i].GetSurname());
			fprintf(file, " %s ", list[i].GetSecSurname());
			fprintf(file, " %d ", list[i].GetHomePh());
			fprintf(file, " %d ", list[i].GetWorkPh());
			fprintf(file, " %d ", list[i].GetMobilePh());
			fprintf(file, "%s ", list[i].GetAddInfo());
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

//добавление контакта
void AddContact(Contact* list, int& size, char filename[])
{
	size += 1;
	list[size - 1] = Contact();
	list[size - 1].Input();
	ClearFileContents(filename);
	WriteContactToFile(list, size);
}

//удаление контакта
void DeleteContact(Contact* list, int& length, char filename[])
{
	int temp = -1;

	char* name = new char[20];
	cout << "Enter name : ";
	cin >> name;
	int size = strlen(name);
	char* Name = new char[size + 1];
	strcpy_s(Name, size + 1, name);

	char* surname = new char[20];
	cout << "Enter surname : ";
	cin >> surname;
	size = strlen(surname);
	char* Surname = new char[size + 1];
	strcpy_s(Surname, size + 1, surname);

	char* s_surname = new char[20];
	cout << "Enter second surname : ";
	cin >> s_surname;
	size = strlen(s_surname);
	char* S_Surname = new char[size + 1];
	strcpy_s(S_Surname, size + 1, s_surname);

	delete[] name;
	delete[] surname;
	delete[] s_surname;

	for (int i = 0; i < length; i++)
	{
		if (strcmp(list[i].GetName(), Name) == 0 && strcmp(list[i].GetSurname(), Surname) == 0 && strcmp(list[i].GetSecSurname(), S_Surname) == 0)
		{
			temp = i;
			break;
		}
	}

	delete[] Name;
	delete[] Surname;
	delete[] S_Surname;

	if (temp != -1)
	{
		for (int i = temp; i < length - 1; i++)
		{
			list[i] = list[i].CopyDelete(list[i+1]);
		}
		length--;
	}
	else
	{
		cout << "Contact not found." << endl;
	}

	ClearFileContents(filename);
	WriteContactToFile(list, length);
}

//ф-ия которая вызывает другие ф-ии согласно выбору в меню пользователя
void PerformAction(int option, Contact* list, int& size, char filename[])
{
	if (option == 1) ViewContactsFromFile();
	else if (option == 2) SearchByName(list, size);
	else if (option == 3) AddContact(list, size, filename);
	else if (option == 4) DeleteContact(list, size, filename);
	else if (option == 0) { exit(0); }

	char temp;
	cout << endl << "Enter smth to continue...";
	cin >> temp;
}
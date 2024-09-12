#include "PhoneBook.h"
#include<iostream>
#include<Windows.h>
using namespace std;

Contact::Contact()
{
	name = nullptr;
	surname = nullptr;
	second_surname = nullptr;
	home_phone = 0;
	work_phone = 0;
	mobile_phone = 0;
	additional_info = nullptr;
}
Contact::Contact(const char* Name, const char* Surname, const char* S_Surname, int h_phone, int w_phone, int m_phone, const char* a_info)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);

	surname = new char[strlen(Surname) + 1];
	strcpy_s(surname, strlen(Surname) + 1, Surname);
	
	second_surname = new char[strlen(S_Surname) + 1];
	strcpy_s(second_surname, strlen(S_Surname) + 1, S_Surname);

	home_phone = h_phone;
	work_phone = w_phone;
	mobile_phone = m_phone;

	additional_info = new char[strlen(a_info) + 1];
	strcpy_s(additional_info, strlen(a_info) + 1, a_info);
}

char* Contact::GetName() { return name; }
char* Contact::GetSurname() { return surname; }
char* Contact::GetSecSurname() { return second_surname; }
int Contact::GetHomePh() { return home_phone; }
int Contact::GetWorkPh() { return work_phone; }
int Contact::GetMobilePh() { return mobile_phone; }
char* Contact::GetAddInfo() {return additional_info;}

void Contact::Print()
{
	cout << name << " " << surname << " " << second_surname << endl;
	cout << additional_info << endl;
	cout << "Home phone: " << home_phone << endl;
	cout << "Work phone: " << work_phone << endl;
	cout << "Mobile phone: " << mobile_phone << endl << endl;
}
void Contact::Input()
{
	char buff[20];
	cout << "Enter name -> ";
	cin >> buff;
	if (name != nullptr) delete[] name;

	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);

	cout << "Enter surname -> ";
	cin >> buff;
	if (surname != nullptr) delete[] surname;

	surname = new char[strlen(buff) + 1];
	strcpy_s(surname, strlen(buff) + 1, buff);

	cout << "Enter second surname -> ";
	cin >> buff;
	if (second_surname != nullptr) delete[] second_surname;

	second_surname = new char[strlen(buff) + 1];
	strcpy_s(second_surname, strlen(buff) + 1, buff);

	cout << "Enter home phone -> ";
	cin >> home_phone;

	cout << "Enter work phone -> ";
	cin >> work_phone;

	cout << "Enter mobile phone -> ";
	cin >> mobile_phone;

	cout << "Enter additional info -> ";
	cin >> buff;
	if (additional_info != nullptr) delete[] additional_info;

	additional_info = new char[strlen(buff) + 1];
	strcpy_s(additional_info, strlen(buff) + 1, buff);
}
Contact::~Contact()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (surname != nullptr)
	{
		delete[] surname;
	}
	if (second_surname != nullptr)
	{
		delete[] second_surname;
	}
	if (additional_info != nullptr)
	{
		delete[] additional_info;
	}
}
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
Contact& Contact::CopyDelete(const Contact& other)
{

	// Очищення поточних даних
	delete[] name;
	delete[] surname;
	delete[] second_surname;
	delete[] additional_info;

	if (other.name != nullptr)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
	else
	{
		name = nullptr;
	}

	if (other.surname != nullptr)
	{
		surname = new char[strlen(other.surname) + 1];
		strcpy_s(surname, strlen(other.surname) + 1, other.surname);
	}
	else
	{
		surname = nullptr;
	}

	if (other.second_surname != nullptr)
	{
		second_surname = new char[strlen(other.second_surname) + 1];
		strcpy_s(second_surname, strlen(other.second_surname) + 1, other.second_surname);
	}
	else
	{
		second_surname = nullptr;
	}
	
	home_phone = other.home_phone;
	work_phone = other.work_phone;
	mobile_phone = other.mobile_phone;

	if (other.additional_info != nullptr)
	{
		additional_info = new char[strlen(other.additional_info) + 1];
		strcpy_s(additional_info, strlen(other.additional_info) + 1, other.additional_info);
	}
	else
	{
		additional_info = nullptr;
	}

	return *this;
}

char* Contact::GetName() const { return name; }
char* Contact::GetSurname() const { return surname; }
char* Contact::GetSecSurname() const { return second_surname; }
int Contact::GetHomePh() const { return home_phone; }
int Contact::GetWorkPh() const { return work_phone; }
int Contact::GetMobilePh() const { return mobile_phone; }
char* Contact::GetAddInfo() const {return additional_info;}

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
	char buff[100];
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
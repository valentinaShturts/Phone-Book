#pragma once
class Contact
{
	char* name;
	char* surname;
	char* second_surname;
	int home_phone;
	int work_phone;
	int mobile_phone;
	char* additional_info;
public:
	////  prototype 
	Contact();
	Contact(const char*, const char*, const char*, int, int, int, const char*);
	char* GetName();
	char* GetSurname();
	char* GetSecSurname();
	int GetHomePh();
	int GetWorkPh();
	int GetMobilePh();
	char* GetAddInfo();
	void Print();
	void Input();
	~Contact();
};

void ClearFileContents(char filename[]);
void ShowMenu();
void WriteContactToFile(const Contact* list, int& size);
void ViewContactsFromFile();
void PerformAction(int option, Contact* list, int& size, char filename[]);
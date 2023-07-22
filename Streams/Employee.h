#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_STR 50
class Employee
{
	char* name;
	char* surname;
	char* jobTitle;
	double salary;
public:
	Employee() : name{ new char[MAX_STR] {"none"} }, surname{ new char[MAX_STR] {"none"} }, jobTitle{ new char[MAX_STR] {"none"}}, salary{0} {};

	void changeName(char* name);
	void changeSurname(char* surname);
	void changeJobTitle(char* jobTitle);
	void changeSalary(double salary);
	void PrintEmployee();
	void saveData(Employee* empl,const char* fileName, int sizeFile);
	void loadData(Employee*& empl,const char* fileName, int& sizeFile);
	Employee& operator=(const Employee& other);

	~Employee();
};


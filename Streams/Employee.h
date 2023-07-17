#pragma once
#include <iostream>
using namespace std;
class Employee
{
	string name;
	string surname;
	string jobTitle;
	double salary;
public:
	Employee() : name{ "none" }, surname{ "none" }, jobTitle{ "none" }, salary{ 0 } {};
	Employee(string name, string surname, string jobTitle, double salary);
	void changeName(string name);
	void changeSurname(string surname);
	void changeJobTitle(string jobTitle);
	void changeSalary(double salary);
	void PrintEmployee();
};


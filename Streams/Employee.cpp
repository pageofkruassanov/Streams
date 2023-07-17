#include "Employee.h"

Employee::Employee(string name, string surname, string jobTitle, double salary)
{
	this->name = name;
	this->surname = surname;
	this->jobTitle = jobTitle;
	if (salary < 0)
		throw exception("Error data. Problem with salary in constructor.");
	else
		this->salary = salary;
}

void Employee::changeName(string name)
{
	this->name = name;
}

void Employee::changeSurname(string surname)
{
	this->surname = surname;
}

void Employee::changeJobTitle(string jobTitle)
{
	this->jobTitle = jobTitle;
}

void Employee::changeSalary(double salary)
{
	if (salary < 0)
		throw exception("Error data. Problem with salary in method 'changeSalary'");
	else
		this->salary = salary;
}

void Employee::PrintEmployee()
{
	cout << "-----Info about employee-----" << endl;
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Job title: " << jobTitle << endl;
	cout << "Salary: " << salary << endl;
}

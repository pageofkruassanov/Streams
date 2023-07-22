#include "Employee.h"


void Employee::changeName(char* name)
{
	strcpy_s(this->name, MAX_STR, name);
}

void Employee::changeSurname(char* surname)
{
	strcpy_s(this->surname, MAX_STR, surname);
}

void Employee::changeJobTitle(char* jobTitle)
{
	strcpy_s(this->jobTitle, MAX_STR, jobTitle);
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
	cout << "--Info about employee--" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Surname: " << this->surname << endl;
	cout << "Job title: " << this->jobTitle << endl;
	cout << "Salary: " << this->salary << endl;
}

void Employee::saveData(Employee* empl,const char* fileName, int sizeFile)
{
	ofstream tempFile(fileName, ios::binary);
	tempFile.write(reinterpret_cast<const char*>(&sizeFile), sizeof(sizeFile));
	for (int i = 0; i < sizeFile; i++) {
		tempFile.write(reinterpret_cast<const char*>(&*empl[i].name), MAX_STR);

		tempFile.write(reinterpret_cast<const char*>(&*empl[i].surname), MAX_STR);

		tempFile.write(reinterpret_cast<const char*>(&*empl[i].jobTitle), MAX_STR);

		tempFile.write(reinterpret_cast<const char*>(&empl[i].salary), sizeof(salary));
	}
	tempFile.close();
}

void Employee::loadData(Employee*& empl,const char* fileName, int& sizeFile)
{
	ifstream tempFile(fileName, ios::binary);

	tempFile.read(reinterpret_cast<char*>(&sizeFile), sizeof(sizeFile));

	Employee* tempEmpl = new Employee[sizeFile];
	for (int i = 0; i < sizeFile; i++) {
		tempFile.read(reinterpret_cast<char*>(&*tempEmpl[i].name), MAX_STR);

		tempFile.read(reinterpret_cast<char*>(&*tempEmpl[i].surname), MAX_STR);

		tempFile.read(reinterpret_cast<char*>(&*tempEmpl[i].jobTitle), MAX_STR);

		tempFile.read(reinterpret_cast<char*>(&tempEmpl[i].salary), sizeof(tempEmpl[i].salary));
	}
	tempFile.close();
	delete empl;
	empl = tempEmpl;
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other) {
		strcpy_s(this->name, MAX_STR, other.name);
		strcpy_s(this->surname, MAX_STR, other.surname);
		strcpy_s(this->jobTitle, MAX_STR, other.jobTitle);
		this->salary = other.salary;
	}
	return *this;
}

Employee::~Employee()
{
	delete name;
	delete surname;
	delete jobTitle;
}

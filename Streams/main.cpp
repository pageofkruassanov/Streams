#include <iostream>
#include "conio.h"
#include "Employee.h"
#include <string>
#include "Func.h"
using namespace std;

// ofstream - запись в файл
// ifstream - считывание с файлу
// fstream - запись/считывание




int main()
{
    const char* fileName = "employee.bin";
    setlocale(0, "Rus");
    int sizeEmpl = 0;
    Employee* empl = new Employee;
    empl->loadData(empl,fileName, sizeEmpl);


    const int sizeMenu = 3;
    string menu[sizeMenu] = { "1.Add Employee", "2.Print all employees", "3.Delete employee" };
    int arrow = 0;
    char symbol;
    while (true) {
        for (int i = 0; i < sizeMenu; i++) {
            if (arrow == i)
                cout << "*";
            if (arrow == i)
                cout << menu[i] << endl;
            else
                cout << " " << menu[i] << endl;
        }
        symbol = _getch();
        switch (symbol) {
            // press W
        case 'w': {
            if (arrow == 0)
                arrow = 2;
            else
                --arrow;
            break;
        }
                // press S
        case 's': {
            if (arrow == 2)
                arrow = 0;
            else
                ++arrow;
            break;
        }
                // press ENTER:
        case 13:
        {
            system("cls");
            //add employee:
            if (arrow == 0) {
                Employee* tempEmpl = new Employee[sizeEmpl + 1];
                for (int i = 0; i < sizeEmpl; i++) {
                    tempEmpl[i] = empl[i];
                }
                // input buffer check:
                clearInputBuffer();
                cout << "Введите имя сотрудника: ";
                char* name = new char[MAX_STR];
                cin.getline(name, MAX_STR);
                tempEmpl[sizeEmpl].changeName(name);
                cout << endl;

                clearInputBuffer();
                cout << "Введите фамилию сотрудника: ";
                char* surname = new char[MAX_STR];
                cin.getline(surname, MAX_STR);
                tempEmpl[sizeEmpl].changeSurname(surname);
                cout << endl;

                clearInputBuffer();
                cout << "Введите должность сотрудника: ";
                char* jobTitle = new char[MAX_STR];
                cin.getline(jobTitle, MAX_STR);
                tempEmpl[sizeEmpl].changeJobTitle(jobTitle);
                cout << endl;

                clearInputBuffer();
                cout << "Введите З/П сотрудника: ";
                double salary;
                try {
                    cin >> salary;
                    tempEmpl[sizeEmpl].changeSalary(salary);
                }
                catch (const exception& ex) {
                    cerr << ex.what() << endl;
                    cout << "Введите З/П сотрудника: ";
                    cin >> salary;
                    tempEmpl[sizeEmpl].changeSalary(salary);
                }
                empl = tempEmpl;
                sizeEmpl++;
                empl->saveData(empl, fileName, sizeEmpl);
                cout << endl << "-------------" << endl << "Сотрудник успешно добавлен!" << endl;
                system("pause");
            }
            else if (arrow == 1) {
                system("cls");
                for (int i = 0; i < sizeEmpl; i++) {
                    cout << "Employee #" << i + 1 << endl;
                    empl[i].PrintEmployee();
                    cout << "---------------" << endl;
                }
                system("pause");
            }
            else if (arrow == 2) {
                system("cls");
                cout << "Введите номер сотрудника: ";
                int number;
                cin >> number;
                if (sizeEmpl == 0) {
                    system("cls");
                    cout << "Список сотрудников пуст" << endl;
                    system("pause");
                }
                else if (number <= 0 || number > sizeEmpl) {
                    system("cls");
                    cout << "Error input data" << endl;
                    system("pause");
                }
                else {
                    Employee* tempEmpl = new Employee[sizeEmpl - 1];

                    for (int i = 0; i < sizeEmpl - 1; i++) {
                        if (number - 1 < i) {
                            tempEmpl[i] = empl[i];
                        }
                        else {
                            tempEmpl[i] = empl[i + 1];
                        }
                    }
                    sizeEmpl--;
                    empl = tempEmpl;
                    empl->saveData(empl, "employee.bin", sizeEmpl);
                    cout << endl << "-------------" << endl << "Сотрудник успешно удален!" << endl;
                    system("pause");
                }
            }
            break;
        }
        // press ESC
        case 27: {
            system("cls");
            break;
        }
        }
        system("cls");
    }
}


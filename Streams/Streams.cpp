#include <iostream>
#include "conio.h"
using namespace std;

// ofstream - запись в файл
// ifstream - считывание с файлу
// fstream - запись/считывание




int main()
{
    const int sizeMenu = 3;
    string menu[sizeMenu] = { "1.Add Employee", "2.Print all employees", "3.Delete employee" };
    int arrow = 0;
    char symbol;
    while (true) {
        for (int i = 0; i < sizeMenu; i++) {
            if (arrow = i)
                cout << "*";
            if (arrow = i)
                cout << menu[i] << endl;
            else
                cout << " " << menu[i] << endl;
        }
        symbol = _getch();
        if (symbol == 'w') {
            if (arrow == 0)
                arrow = 2;
            else
                --arrow;
        }
        else if (symbol == 's') {
            if (arrow == 2)
                arrow = 0;
            else
                ++arrow;
        }
        system("cls");
    }
}


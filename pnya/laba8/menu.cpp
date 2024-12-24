#include "menu.h"
#include <iostream>
#include <locale>
#include <iomanip>

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

Menu::Menu() :  trollMenu() {}

void Menu::showMenu() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        std::cout << GREEN;
        std::cout << "\nГлавное Меню:\n";
        std::cout << "1. Меню Самосвалов\n";
        std::cout << "2. Меню Автобусов\n";
        std::cout << "3. Меню Троллейбусов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";

        std::cin >> choice;

        switch (choice) {
        case 1:  break;
        case 2:  break;
        case 3: trollMenu.showMenu(); break;
        case 0: std::cout << "Выход из программы.\n"; break;
        default: std::cout << RED << "Некорректный выбор. Повторите попытку." << RESET << "\n";
        }
    } while (choice != 0);
}

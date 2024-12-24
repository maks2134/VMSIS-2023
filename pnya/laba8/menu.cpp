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
        std::cout << "\n������� ����:\n";
        std::cout << "1. ���� ����������\n";
        std::cout << "2. ���� ���������\n";
        std::cout << "3. ���� ������������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1:  break;
        case 2:  break;
        case 3: trollMenu.showMenu(); break;
        case 0: std::cout << "����� �� ���������.\n"; break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}

#include "DumpMenu.h"
#include "Exception_Vvod.h"

DumpMenu::DumpMenu() : dumps() {}

void DumpMenu::addDump() {
    try {
        Dump newDump;
        std::cin >> newDump;
        dumps.push(newDump);
        std::cout << GREEN << "�������� ��������." << std::endl;
    }
    catch (const Exception_Vvod& e){
        std::cerr << "������ �����: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "����������� ������: " << e.what() << std::endl;
    }
}

void DumpMenu::displayDumps() const {
    if (dumps.isEmpty()) {
        std::cout << GREEN << "��� ������ ��� ����������." << RESET << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "��������"
        << std::setw(15) << "������"
        << std::setw(10) << "���"
        << std::setw(15) << "����"
        << std::setw(10) << "���"
        << std::setw(15) << "������ ������" << std::endl;

    std::cout << std::string(85, '-') << "\n";

    dumps.forEach([](const Dump& dump) {
        std::cout << dump << std::endl;
        });
}

void DumpMenu::removeDump() {
    if (dumps.isEmpty()) {
        std::cout << RED << "��� ���������� ��� ��������." << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "����� ��������: " << dumps.top() << RESET << std::endl;
        dumps.pop();
    }
}

void DumpMenu::showMenu() {
    int choice;
    do {
        std::cout << "\n���� ����������:\n";
        std::cout << "1. �������� ��������\n";
        std::cout << "2. �������� ��� ���������\n";
        std::cout << "3. ������� ��������� ��������\n";
        std::cout << "0. ��������� � ������� ����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addDump(); break;
        case 2: displayDumps(); break;
        case 3: removeDump(); break;
        case 0: break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}

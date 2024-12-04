#include "BusMenu.h"

BusMenu::BusMenu() : buses() {}

void BusMenu::addBus() {
    Bus newBus;
    std::cin >> newBus;
    buses.push(newBus);
    std::cout << BLUE << "������� ��������." << std::endl;
}

void BusMenu::displayBuses() const {
    if (buses.isEmpty()) {
        std::cout << RED << "��� ������ ��� ���������." << RESET << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "��������"
        << std::setw(15) << "������"
        << std::setw(10) << "���"
        << std::setw(15) << "����"
        << std::setw(15) << "��� ������"
        << std::setw(15) << "������� (��)" << std::endl;

    std::cout << std::string(85, '-') << "\n";

    buses.forEach([](const Bus& bus) {
        std::cout << bus << std::endl;
        });
}

void BusMenu::removeBus() {
    if (buses.isEmpty()) {
        std::cout << RED << "��� ��������� ��� ��������." << RESET << std::endl;
    }
    else {
        std::cout << BLUE << "����� �������: " << buses.top() << RESET << std::endl;
        buses.pop();
    }
}

void BusMenu::showMenu() {
    int choice;
    do {
        std::cout << BLUE;
        std::cout << "\n���� ���������:\n";
        std::cout << "1. �������� �������\n";
        std::cout << "2. �������� ��� ��������\n";
        std::cout << "3. ������� ��������� �������\n";
        std::cout << "0. ��������� � ������� ����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addBus(); break;
        case 2: displayBuses(); break;
        case 3: removeBus(); break;
        case 0: break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}

#include "TrollMenu.h"

TrollMenu::TrollMenu() : trolls() {}

void TrollMenu::addTroll() {
    Troll newTroll;
    std::cin >> newTroll;
    trolls.push(newTroll);
    std::cout << YELLOW << "���������� ��������." << std::endl;
}

void TrollMenu::displayTrolls() const {
    if (trolls.isEmpty()) {
        std::cout << RED << "��� ������ ��� ������������." << RESET << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "��������"
        << std::setw(15) << "������"
        << std::setw(10) << "���"
        << std::setw(15) << "����"
        << std::setw(15) << "��� ������"
        << std::setw(15) << "�������-��������" << std::endl;

    std::cout << std::string(85, '-') << "\n";

    trolls.forEach([](const Troll& troll) {
        std::cout << troll << std::endl;
        });
}

void TrollMenu::removeTroll() {
    if (trolls.isEmpty()) {
        std::cout << RED << "��� ������������ ��� ��������." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "����� ����������: " << trolls.top() << RESET << std::endl;
        trolls.pop();
    }
}

void TrollMenu::showMenu() {
    std::cout << YELLOW;
    int choice;
    do {
        std::cout << "\n���� ������������:\n";
        std::cout << "1. �������� ����������\n";
        std::cout << "2. �������� ��� �����������\n";
        std::cout << "3. ������� ��������� ����������\n";
        std::cout << "0. ��������� � ������� ����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addTroll(); break;
        case 2: displayTrolls(); break;
        case 3: removeTroll(); break;
        case 0: break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}

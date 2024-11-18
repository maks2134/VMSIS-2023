#include "Menu.h"
#include <iomanip>

#define GREEN   "\033[32m"

Menu::Menu()
    : dumpStack(10), busStack(10), trollStack(10) {}

void Menu::addDump() {
    Dump newDump;
    std::cin >> newDump;
    try {
        dumpStack.push(newDump);
        std::cout << "�������� �������� � ����.\n";
    }
    catch (const std::overflow_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Menu::addBus() {
    Bus newBus;
    std::cin >> newBus;
    try {
        busStack.push(newBus);
        std::cout << "������� �������� � ����.\n";
    }
    catch (const std::overflow_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Menu::addTroll() {
    Troll newTroll;
    std::cin >> newTroll;
    try {
        trollStack.push(newTroll);
        std::cout << "���������� �������� � ����.\n";
    }
    catch (const std::overflow_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Menu::displayDumps() const {
    if (dumpStack.isEmpty()) {
        std::cout << "��� ���������� ��� �����������.\n";
        return;
    }

    const std::string sep = "|";
    const int width = 20;

    printSeparator(sep, 7, width);
    std::cout << sep
        << std::setw(width) << std::left << "��������" << sep
        << std::setw(width) << "������" << sep
        << std::setw(width) << "���" << sep
        << std::setw(width) << "����������������" << sep
        << std::setw(width) << "���" << sep
        << std::setw(width) << "����� ������" << sep
        << std::setw(width) << "������ ������" << sep << "\n";
    printSeparator(sep, 7, width);

    // Assuming Stack has a way to iterate without copying
    for (const auto& dump : dumpStack) {
        std::cout << sep
            << std::setw(width) << std::left << dump.getCompany() << sep
            << std::setw(width) << dump.getModal() << sep
            << std::setw(width) << dump.getYear() << sep
            << std::setw(width) << dump.getLoadCapacity() << sep
            << std::setw(width) << dump.getNumberOfAxles() << sep
            << std::setw(width) << dump.getBedLength() << sep
            << std::setw(width) << dump.getBedWidth() << sep << "\n";
    }
    printSeparator(sep, 7, width);
}

void Menu::displayBuses() const {
    if (busStack.isEmpty()) {
        std::cout << "��� ��������� ��� �����������.\n";
        return;
    }

    const std::string sep = "|";
    const int width = 20;

    printSeparator(sep, 6, width);
    std::cout << sep
        << std::setw(width) << std::left << "��������" << sep
        << std::setw(width) << "������" << sep
        << std::setw(width) << "���" << sep
        << std::setw(width) << "��� ������" << sep
        << std::setw(width) << "���-�� ����" << sep
        << std::setw(width) << "������� � ��" << sep << "\n";
    printSeparator(sep, 6, width);

    for (const auto& bus : busStack) {
        std::cout << sep
            << std::setw(width) << std::left << bus.getCompany() << sep
            << std::setw(width) << bus.getModal() << sep
            << std::setw(width) << bus.getYear() << sep
            << std::setw(width) << bus.getBodyType() << sep
            << std::setw(width) << bus.getSeatsNumber() << sep
            << std::setw(width) << bus.getMarchuteKm() << sep << "\n";
    }
    printSeparator(sep, 6, width);
}

void Menu::displayTrolls() const {
    if (trollStack.isEmpty()) {
        std::cout << "��� ������������ ��� �����������.\n";
        return;
    }

    const std::string sep = "|";
    const int width = 20;

    printSeparator(sep, 6, width);
    std::cout << sep
        << std::setw(width) << std::left << "��������" << sep
        << std::setw(width) << "������" << sep
        << std::setw(width) << "���" << sep
        << std::setw(width) << "��� ������" << sep
        << std::setw(width) << "���-�� ����" << sep
        << std::setw(width) << "�������. ��������" << sep << "\n";
    printSeparator(sep, 6, width);

    for (const auto& troll : trollStack) {
        std::cout << sep
            << std::setw(width) << std::left << troll.getCompany() << sep
            << std::setw(width) << troll.getModal() << sep
            << std::setw(width) << troll.getYear() << sep
            << std::setw(width) << troll.getBodyType() << sep
            << std::setw(width) << troll.getSeatsNumber() << sep
            << std::setw(width) << troll.getElectricPower() << sep << "\n";
    }
    printSeparator(sep, 6, width);
}

void Menu::printSeparator(const std::string& sep, int columns, int width) const {
    for (int i = 0; i < columns; ++i) {
        std::cout << sep;
        for (int j = 0; j < width; ++j) {
            std::cout << "-";
        }
    }
    std::cout << sep << "\n";
}

void Menu::removeDump() {
    if (!dumpStack.isEmpty()) {
        dumpStack.pop();
        std::cout << "�������� ������ �� �����.\n";
    }
    else {
        std::cout << "���� ����, �������� ����������.\n";
    }
}

void Menu::removeBus() {
    if (!busStack.isEmpty()) {
        busStack.pop();
        std::cout << "������� ������ �� �����.\n";
    }
    else {
        std::cout << "���� ����, �������� ����������.\n";
    }
}

void Menu::removeTroll() {
    if (!trollStack.isEmpty()) {
        trollStack.pop();
        std::cout << "���������� ������ �� �����.\n";
    }
    else {
        std::cout << "���� ����, �������� ����������.\n";
    }
}

void Menu::showMenu() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        std::cout << GREEN;

        std::cout << "\n����:\n";
        std::cout << "1. �������� ��������\n";
        std::cout << "2. �������� �������\n";
        std::cout << "3. �������� ����������\n";

        std::cout << "4. �������� ��� ���������\n";
        std::cout << "5. �������� ��� ��������\n";
        std::cout << "6. �������� ��� �����������\n";

        std::cout << "7. ������� ��������\n";
        std::cout << "8. ������� �������\n";
        std::cout << "9. ������� ����������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� �����: ";

        std::cout << GREEN;

        std::cin >> choice;

        switch (choice) {
        case 1:
            addDump();
            break;
        case 2:
            addBus();
            break;
        case 3:
            addTroll();
            break;
        case 4:
            displayDumps();
            break;
        case 5:
            displayBuses();
            break;
        case 6:
            displayTrolls();
            break;
        case 7:
            removeDump();
            break;
        case 8:
            removeBus();
            break;
        case 9:
            removeTroll();
            break;
        case 0:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "������������ �����. ��������� �������.\n";
        }
    } while (choice != 0);
}
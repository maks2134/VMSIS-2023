#include "DumpMenu.h"
#include "Exception_Vvod.h"
#include "DumpFile.h"

DumpMenu::DumpMenu() : dumps() {}

void DumpMenu::addDump() {
    try {
        Dump newDump;
        std::cin >> newDump;
        dumps.push(newDump);
        std::cout << GREEN << "�������� ��������." << std::endl;
    }
    catch (const Exception_Vvod& e) {
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

void DumpMenu::saveDumpsToFile() {
    DumpFile dumpFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\dump.txt");
    dumpFile.saveToFile(dumps);
}

void DumpMenu::loadDumpsFromFile() {
    DumpFile dumpFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\dump.txt");
    dumpFile.loadFromFile(dumps);
}

void DumpMenu::sortDumps() {
    Algorithms<Dump>::sort(dumps, [](const Dump& a, const Dump& b) {
        return a.getYear() < b.getYear();
        });

    std::cout << YELLOW << "��������� ������������� �� ���� ������� (�� �����������)." << RESET << std::endl;
}

void DumpMenu::removeByCondition() {
    int maxYear;
    std::cout << "������� ������������ ��� ������� ��� ��������: ";
    std::cin >> maxYear;

    Algorithms<Dump>::removeIf(dumps, [maxYear](const Dump& d) {
        return d.getYear() <= maxYear;
        });

    std::cout << YELLOW << "������� ���������, ���������� �� ��� � " << maxYear << " ���." << RESET << std::endl;
}

void DumpMenu::filterDumps() const {
    Stack<Dump> filteredDumps = Algorithms<Dump>::filter(dumps, [](const Dump& d) {
        int minLoad;
        std::cout << "������� ����������� ���������������� ��� ����������: ";
        std::cin >> minLoad;
        return d.getBedWidth() >= minLoad;
        });

    if (filteredDumps.isEmpty()) {
        std::cout << RED << "��� ����������, ��������������� �������." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "��������������� ���������:" << RESET << std::endl;
        filteredDumps.forEach([](const Dump& dump) {
            std::cout << dump << std::endl;
            });
    }
}

void DumpMenu::showMenu() {
    int choice;
    do {
        std::cout << "\n���� ����������:\n";
        std::cout << "1. �������� ��������\n";
        std::cout << "2. �������� ��� ���������\n";
        std::cout << "3. ������� ��������� ��������\n";
        std::cout << "4. ��������� ������ � �����\n";
        std::cout << "5. ��������� ������ � ����\n";
        std::cout << "6. ���������� ����������\n";
        std::cout << "7. �������� �� �������\n";
        std::cout << "8. ���������� ����������\n";
        std::cout << "0. ��������� � ������� ����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addDump(); break;
        case 2: displayDumps(); break;
        case 3: removeDump(); break;
        case 4: loadDumpsFromFile(); break;
        case 5: saveDumpsToFile(); break;
        case 6: sortDumps(); break;
        case 7: removeByCondition(); break;
        case 8: filterDumps(); break;
        case 0: break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}

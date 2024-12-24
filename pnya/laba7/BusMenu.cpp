#include "BusMenu.h"
#include "BusFile.h"
#include "Exception_Vvod.h"

BusMenu::BusMenu() : buses() {}

void BusMenu::addBus() {
    try {
        Bus newBus;
        std::cin >> newBus;
        buses.push(newBus);
        std::cout << "������� ������� ��������!" << std::endl;
    }
    catch (const Exception_Vvod& e) {
        std::cerr << "������ �����: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "����������� ������: " << e.what() << std::endl;
    }
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

void BusMenu::saveBusesToFile() {
    BusFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.txt");
    busFile.saveToFile(buses);
}

void BusMenu::loadBusesFromFile() {
    BusFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.txt");
    busFile.loadFromFile(buses);
}

void BusMenu::sortBuses() {
    Algorithms<Bus>::sort(buses, [](const Bus& a, const Bus& b) {
        return a.getYear() < b.getYear();
        });

    std::cout << YELLOW << "�������� ������������� �� ���� ������� (�� �����������)." << RESET << std::endl;
}

void BusMenu::removeByCondition() {
    int maxYear;
    std::cout << "������� ������������ ��� ������� ��� ��������: ";
    std::cin >> maxYear;

    Algorithms<Bus>::removeIf(buses, [maxYear](const Bus& b) {
        return b.getYear() <= maxYear;
        });

    std::cout << YELLOW << "������� ��������, ���������� �� ��� � " << maxYear << " ���." << RESET << std::endl;
}

void BusMenu::filterBuses() const {
    Stack<Bus> filteredBuses = Algorithms<Bus>::filter(buses, [](const Bus& b) {
        int minSeats;
        std::cout << "������� ����������� ���������� ���� ��� ����������: ";
        std::cin >> minSeats;
        return b.getSeatsNumber() >= minSeats;
        });

    if (filteredBuses.isEmpty()) {
        std::cout << RED << "��� ���������, ��������������� �������." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "��������������� ��������:" << RESET << std::endl;
        filteredBuses.forEach([](const Bus& bus) {
            std::cout << bus << std::endl;
            });
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
        std::cout << "4. ��������� ���������� � ��������� � ����\n";
        std::cout << "5. ��������� �������� � �����\n";
        std::cout << "6. ���������� ���������\n";
        std::cout << "7. �������� �� �������\n";
        std::cout << "8. ���������� ���������\n";
        std::cout << "0. ��������� � ������� ����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addBus(); break;
        case 2: displayBuses(); break;
        case 3: removeBus(); break;
        case 4: saveBusesToFile(); break;
        case 5: loadBusesFromFile(); break;
        case 6: sortBuses(); break;
        case 7: removeByCondition(); break;
        case 8: filterBuses(); break;
        case 0: break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}
#include "TrollMenu.h"
#include "Exception_Vvod.h"
#include "Algorithms.h"

TrollMenu::TrollMenu() : trolls() {}

void TrollMenu::addTroll() {
    try {
        Troll newTroll;
        std::cin >> newTroll;
        trolls.insert({ newTroll.getElectricPower(), newTroll });
        std::cout << YELLOW << "���������� ��������." << std::endl;
    }
    catch (const Exception_Vvod& e) {
        std::cerr << "������ �����: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "����������� ������: " << e.what() << std::endl;
    }
}

void TrollMenu::displayTrolls() const {
    if (trolls.empty()) {
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

    for (const auto& pair : trolls) {
        std::cout << pair.second << std::endl;
    }
}

void TrollMenu::removeTroll() {
    if (trolls.empty()) {
        std::cout << RED << "��� ������������ ��� ��������." << RESET << std::endl;
    }
    else {
        auto it = trolls.begin();
        std::cout << YELLOW << "����� ����������: " << it->second << RESET << std::endl;
        trolls.erase(it);
    }
}

void TrollMenu::saveTrollsToFile() {
    TrollFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.txt");
    busFile.saveToFile(trolls);
}

void TrollMenu::loadTrollsFromFile() {
    TrollFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.txt");
    busFile.loadFromFile(trolls);
}

void TrollMenu::searchTroll() const {
    try {
        int minPower;
        std::cout << "������� ����������� �������-�������� ��� ������: ";
        std::cin >> minPower;

        auto it = trolls.lower_bound(minPower);
        if (it != trolls.end()) {
            std::cout << YELLOW << "��������� ����������:" << std::endl;
            std::cout << it->second << RESET << std::endl;
        }
        else {
            std::cout << RED << "���������� �� ������." << RESET << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << RED << "������: " << e.what() << RESET << std::endl;
    }
}

void TrollMenu::sortTrolls() {
    // multimap ������������� ��������� �������� �� �����, ��� ��� ���������� �� ���������
    std::cout << YELLOW << "����������� ������������� �� �������-�������� (�� �����������)." << RESET << std::endl;
}

void TrollMenu::removeByCondition() {
    int maxYear;
    std::cout << "������� ������������ ��� ������� ��� ��������: ";
    std::cin >> maxYear;

    for (auto it = trolls.begin(); it != trolls.end(); ) {
        if (it->second.getYear() <= maxYear) {
            it = trolls.erase(it);
        }
        else {
            ++it;
        }
    }

    std::cout << YELLOW << "������� �����������, ���������� �� ��� � " << maxYear << " ���." << RESET << std::endl;
}

void TrollMenu::filterTrolls() const {
    int minSeats;
    std::cout << "������� ����������� ���������� ���� ��� ����������: ";
    std::cin >> minSeats;

    std::multimap<int, Troll> filteredTrolls;
    for (const auto& pair : trolls) {
        if (pair.second.getSeatsNumber() >= minSeats) {
            filteredTrolls.insert(pair);
        }
    }

    if (filteredTrolls.empty()) {
        std::cout << RED << "��� ������������, ��������������� �������." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "��������������� �����������:" << RESET << std::endl;
        for (const auto& pair : filteredTrolls) {
            std::cout << pair.second << std::endl;
        }
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
        std::cout << "4. ��������� ������ � ����\n";
        std::cout << "5. ��������� ������ c �����\n";
        std::cout << "6. ����� �����������\n";
        std::cout << "7. ���������� ������������\n";
        std::cout << "8. �������� �� �������\n";
        std::cout << "9. ���������� ������������\n";
        std::cout << "0. ��������� � ������� ����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addTroll(); break;
        case 2: displayTrolls(); break;
        case 3: removeTroll(); break;
        case 4: saveTrollsToFile(); break;
        case 5: loadTrollsFromFile(); break;
        case 6: searchTroll(); break;
        case 7: sortTrolls(); break;
        case 8: removeByCondition(); break;
        case 9: filterTrolls(); break;
        case 0: break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}

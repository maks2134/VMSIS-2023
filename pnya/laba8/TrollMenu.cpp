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
        std::cout << RED << "��� ������ ��� ������������." << RED << std::endl;
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
        std::cout << RED << "��� ������������ ��� ��������." << RED << std::endl;
    }
    else {
        auto it = trolls.begin();
        std::cout << YELLOW << "����� ����������: " << it->second << YELLOW << std::endl;
        trolls.erase(it);
    }
}

//void TrollMenu::saveTrollsToFile() {
//    TrollFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\Troll.txt");
//    busFile.saveToFile(trolls);
//}
//
//void TrollMenu::loadTrollsFromFile() {
//    TrollFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\Troll.txt");
//    busFile.loadFromFile(trolls);
//}

void TrollMenu::searchTroll() const {
    try {
        Troll foundTroll = Algorithms<int, Troll>::findByCondition(trolls, [](const Troll& t) {
            int minPower;
            std::cout << "������� ����������� �������-�������� ��� ������: ";
            std::cin >> minPower;
            return t.getElectricPower() >= minPower;
            });

        std::cout << YELLOW << "��������� ����������:" << std::endl;
        std::cout << foundTroll << YELLOW << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "������: " << e.what() << YELLOW << std::endl;
    }
}

void TrollMenu::sortTrolls() {
    // multimap ������������� ��������� �������� �� �����, ��� ��� ���������� �� ���������
    std::cout << YELLOW << "����������� ������������� �� �������-�������� (�� �����������)." << YELLOW << std::endl;
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

    std::cout << YELLOW << "������� �����������, ���������� �� ��� � " << maxYear << " ���." << YELLOW << std::endl;
}

//void TrollMenu::saveTrollsToBinaryFile() {
//    TrollFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\Troll.bin");
//    busFile.saveToBinaryFile(trolls);
//}
//
//void TrollMenu::loadTrollsFromBinaryFile() {
//    TrollFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\Troll.bin");
//    busFile.loadFromBinaryFile(trolls);
//}

void TrollMenu::countTrollsByCondition() const {
    int minSeats;
    std::cout << "������� ����������� ���������� ���� ��� ��������: ";
    std::cin >> minSeats;

    int count = Algorithms<int, Troll>::countIf(trolls, [minSeats](const Troll& t) {
        return t.getSeatsNumber() >= minSeats;
        });

    std::cout << YELLOW << "���������� ������������ � �� ����� ��� " << minSeats << " ����: " << count << YELLOW << std::endl;
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
        std::cout << "6. ��������� ������ � �������� ����\n";
        std::cout << "7. ��������� ������ �� ��������� �����\n";
        std::cout << "8. ����� �����������\n";
        std::cout << "9. ���������� ������������\n";
        std::cout << "10. �������� �� �������\n";
        std::cout << "11. ����������� ����������\n";
        std::cout << "0. ��������� � ������� ����\n";
        std::cout << "�������� �����: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addTroll(); break;
        case 2: displayTrolls(); break;
        case 3: removeTroll(); break;
        //case 4: saveTrollsToFile(); break;
        //case 5: loadTrollsFromFile(); break;
        //case 6: saveTrollsToBinaryFile(); break;
        //case 7: loadTrollsFromBinaryFile(); break;
        case 8: searchTroll(); break;
        case 9: sortTrolls(); break;
        case 10: removeByCondition(); break;
        case 11: countTrollsByCondition(); break;
        case 0: break;
        default: std::cout << RED << "������������ �����. ��������� �������." << RESET << "\n";
        }
    } while (choice != 0);
}

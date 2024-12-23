#include "TrollMenu.h"
#include "Exception_Vvod.h"
#include "Algorithms.h"

TrollMenu::TrollMenu() : trolls() {}

void TrollMenu::addTroll() {
    try {
        Troll newTroll;
        std::cin >> newTroll;
        trolls.push(newTroll);
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
        Troll foundTroll = Algorithms<Troll>::findByCondition(trolls, [](const Troll& t) {
            int minPower;
            std::cout << "������� ����������� �������-�������� ��� ������: ";
            std::cin >> minPower;
            return t.getElectricPower() >= minPower;
            });

        std::cout << YELLOW << "��������� ����������:" << std::endl;
        std::cout << foundTroll << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "������: " << e.what() << RESET << std::endl;
    }
}

void TrollMenu::sortTrolls() {
    Algorithms<Troll>::sort(trolls, [](const Troll& a, const Troll& b) {
        return a.getElectricPower() < b.getElectricPower();
        });

    std::cout << YELLOW << "����������� ������������� �� �������-�������� (�� �����������)." << RESET << std::endl;
}

void TrollMenu::removeByCondition() {
    int maxYear;
    std::cout << "������� ������������ ��� ������� ��� ��������: ";
    std::cin >> maxYear;

    Algorithms<Troll>::removeIf(trolls, [maxYear](const Troll& t) {
        return t.getYear() <= maxYear;
        });

    std::cout << YELLOW << "������� �����������, ���������� �� ��� � " << maxYear << " ���." << RESET << std::endl;
}

void TrollMenu::filterTrolls() const {
    Stack<Troll> filteredTrolls = Algorithms<Troll>::filter(trolls, [](const Troll& t) {
        int minSeats;
        std::cout << "������� ����������� ���������� ���� ��� ����������: ";
        std::cin >> minSeats;
        return t.getSeatsNumber() >= minSeats;
        });

    if (filteredTrolls.isEmpty()) {
        std::cout << RED << "��� ������������, ��������������� �������." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "��������������� �����������:" << RESET << std::endl;
        filteredTrolls.forEach([](const Troll& troll) {
            std::cout << troll << std::endl;
            });
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

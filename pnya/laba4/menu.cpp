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
        std::cout << "Самосвал добавлен в стек.\n";
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
        std::cout << "Автобус добавлен в стек.\n";
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
        std::cout << "Троллейбус добавлен в стек.\n";
    }
    catch (const std::overflow_error& e) {
        std::cout << e.what() << "\n";
    }
}

void Menu::displayDumps() const {
    if (dumpStack.isEmpty()) {
        std::cout << "Нет самосвалов для отображения.\n";
        return;
    }

    const std::string sep = "|";
    const int width = 20;

    printSeparator(sep, 7, width);
    std::cout << sep
        << std::setw(width) << std::left << "Компания" << sep
        << std::setw(width) << "Модель" << sep
        << std::setw(width) << "Год" << sep
        << std::setw(width) << "Грузоподъемность" << sep
        << std::setw(width) << "Оси" << sep
        << std::setw(width) << "Длина кузова" << sep
        << std::setw(width) << "Ширина кузова" << sep << "\n";
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
        std::cout << "Нет автобусов для отображения.\n";
        return;
    }

    const std::string sep = "|";
    const int width = 20;

    printSeparator(sep, 6, width);
    std::cout << sep
        << std::setw(width) << std::left << "Компания" << sep
        << std::setw(width) << "Модель" << sep
        << std::setw(width) << "Год" << sep
        << std::setw(width) << "Тип кузова" << sep
        << std::setw(width) << "Кол-во мест" << sep
        << std::setw(width) << "Маршрут в км" << sep << "\n";
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
        std::cout << "Нет троллейбусов для отображения.\n";
        return;
    }

    const std::string sep = "|";
    const int width = 20;

    printSeparator(sep, 6, width);
    std::cout << sep
        << std::setw(width) << std::left << "Компания" << sep
        << std::setw(width) << "Модель" << sep
        << std::setw(width) << "Год" << sep
        << std::setw(width) << "Тип кузова" << sep
        << std::setw(width) << "Кол-во мест" << sep
        << std::setw(width) << "Электро. мощность" << sep << "\n";
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
        std::cout << "Самосвал удален из стека.\n";
    }
    else {
        std::cout << "Стек пуст, удаление невозможно.\n";
    }
}

void Menu::removeBus() {
    if (!busStack.isEmpty()) {
        busStack.pop();
        std::cout << "Автобус удален из стека.\n";
    }
    else {
        std::cout << "Стек пуст, удаление невозможно.\n";
    }
}

void Menu::removeTroll() {
    if (!trollStack.isEmpty()) {
        trollStack.pop();
        std::cout << "Троллейбус удален из стека.\n";
    }
    else {
        std::cout << "Стек пуст, удаление невозможно.\n";
    }
}

void Menu::showMenu() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        std::cout << GREEN;

        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить Самосвал\n";
        std::cout << "2. Добавить Автобус\n";
        std::cout << "3. Добавить Троллейбус\n";

        std::cout << "4. Показать все Самосвалы\n";
        std::cout << "5. Показать все Автобусы\n";
        std::cout << "6. Показать все Троллейбусы\n";

        std::cout << "7. Удалить Самосвал\n";
        std::cout << "8. Удалить Автобус\n";
        std::cout << "9. Удалить Троллейбус\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";

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
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Повторите попытку.\n";
        }
    } while (choice != 0);
}
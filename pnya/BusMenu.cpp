#include "BusMenu.h"
#include "BusFile.h"
#include "Exception_Vvod.h"

BusMenu::BusMenu() : buses() {}

void BusMenu::addBus() {
    try {
        Bus newBus;
        std::cin >> newBus;
        buses.push(newBus);
        std::cout << "Автобус успешно добавлен!" << std::endl;
    }
    catch (const Exception_Vvod& e) {
        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Неизвестная ошибка: " << e.what() << std::endl;
    }
}

void BusMenu::displayBuses() const {
    if (buses.isEmpty()) {
        std::cout << RED << "Нет данных для автобусов." << RESET << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "Компания"
        << std::setw(15) << "Модель"
        << std::setw(10) << "Год"
        << std::setw(15) << "Мест"
        << std::setw(15) << "Тип кузова"
        << std::setw(15) << "Маршрут (км)" << std::endl;

    std::cout << std::string(85, '-') << "\n";

    buses.forEach([](const Bus& bus) {
        std::cout << bus << std::endl;
        });
}

void BusMenu::removeBus() {
    if (buses.isEmpty()) {
        std::cout << RED << "Нет автобусов для удаления." << RESET << std::endl;
    }
    else {
        std::cout << BLUE << "Удалён автобус: " << buses.top() << RESET << std::endl;
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

void BusMenu::showMenu() {
    int choice;
    do {
        std::cout << BLUE;
        std::cout << "\nМеню Автобусов:\n";
        std::cout << "1. Добавить Автобус\n";
        std::cout << "2. Показать все Автобусы\n";
        std::cout << "3. Удалить последний Автобус\n";
        std::cout << "4. Сохранить информацию о автобусах в файл\n";
        std::cout << "5. Загрузить автобусы с файла\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите опцию: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addBus(); break;
        case 2: displayBuses(); break;
        case 3: removeBus(); break;
        case 4: saveBusesToFile(); break;
        case 5: loadBusesFromFile(); break;
        case 0: break;
        default: std::cout << RED << "Некорректный выбор. Повторите попытку." << RESET << "\n";
        }
    } while (choice != 0);
}

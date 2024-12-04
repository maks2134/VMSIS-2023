#include "TrollMenu.h"

TrollMenu::TrollMenu() : trolls() {}

void TrollMenu::addTroll() {
    Troll newTroll;
    std::cin >> newTroll;
    trolls.push(newTroll);
    std::cout << YELLOW << "Троллейбус добавлен." << std::endl;
}

void TrollMenu::displayTrolls() const {
    if (trolls.isEmpty()) {
        std::cout << RED << "Нет данных для троллейбусов." << RESET << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "Компания"
        << std::setw(15) << "Модель"
        << std::setw(10) << "Год"
        << std::setw(15) << "Мест"
        << std::setw(15) << "Тип кузова"
        << std::setw(15) << "Электро-мощность" << std::endl;

    std::cout << std::string(85, '-') << "\n";

    trolls.forEach([](const Troll& troll) {
        std::cout << troll << std::endl;
        });
}

void TrollMenu::removeTroll() {
    if (trolls.isEmpty()) {
        std::cout << RED << "Нет троллейбусов для удаления." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "Удалён троллейбус: " << trolls.top() << RESET << std::endl;
        trolls.pop();
    }
}

void TrollMenu::showMenu() {
    std::cout << YELLOW;
    int choice;
    do {
        std::cout << "\nМеню Троллейбусов:\n";
        std::cout << "1. Добавить Троллейбус\n";
        std::cout << "2. Показать все Троллейбусы\n";
        std::cout << "3. Удалить последний Троллейбус\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите опцию: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addTroll(); break;
        case 2: displayTrolls(); break;
        case 3: removeTroll(); break;
        case 0: break;
        default: std::cout << RED << "Некорректный выбор. Повторите попытку." << RESET << "\n";
        }
    } while (choice != 0);
}

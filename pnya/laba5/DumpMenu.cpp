#include "DumpMenu.h"
#include "Exception_Vvod.h"

DumpMenu::DumpMenu() : dumps() {}

void DumpMenu::addDump() {
    try {
        Dump newDump;
        std::cin >> newDump;
        dumps.push(newDump);
        std::cout << GREEN << "Самосвал добавлен." << std::endl;
    }
    catch (const Exception_Vvod& e){
        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Неизвестная ошибка: " << e.what() << std::endl;
    }
}

void DumpMenu::displayDumps() const {
    if (dumps.isEmpty()) {
        std::cout << GREEN << "Нет данных для самосвалов." << RESET << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "Компания"
        << std::setw(15) << "Модель"
        << std::setw(10) << "Год"
        << std::setw(15) << "Груз"
        << std::setw(10) << "Оси"
        << std::setw(15) << "Ширина кузова" << std::endl;

    std::cout << std::string(85, '-') << "\n";

    dumps.forEach([](const Dump& dump) {
        std::cout << dump << std::endl;
        });
}

void DumpMenu::removeDump() {
    if (dumps.isEmpty()) {
        std::cout << RED << "Нет самосвалов для удаления." << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Удалён самосвал: " << dumps.top() << RESET << std::endl;
        dumps.pop();
    }
}

void DumpMenu::showMenu() {
    int choice;
    do {
        std::cout << "\nМеню Самосвалов:\n";
        std::cout << "1. Добавить Самосвал\n";
        std::cout << "2. Показать все Самосвалы\n";
        std::cout << "3. Удалить последний Самосвал\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите опцию: ";

        std::cin >> choice;

        switch (choice) {
        case 1: addDump(); break;
        case 2: displayDumps(); break;
        case 3: removeDump(); break;
        case 0: break;
        default: std::cout << RED << "Некорректный выбор. Повторите попытку." << RESET << "\n";
        }
    } while (choice != 0);
}

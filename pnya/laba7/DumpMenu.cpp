#include "DumpMenu.h"
#include "Exception_Vvod.h"
#include "DumpFile.h"

DumpMenu::DumpMenu() : dumps() {}

void DumpMenu::addDump() {
    try {
        Dump newDump;
        std::cin >> newDump;
        dumps.push(newDump);
        std::cout << GREEN << "Самосвал добавлен." << std::endl;
    }
    catch (const Exception_Vvod& e) {
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

    std::cout << YELLOW << "Самосвалы отсортированы по году выпуска (по возрастанию)." << RESET << std::endl;
}

void DumpMenu::removeByCondition() {
    int maxYear;
    std::cout << "Введите максимальный год выпуска для удаления: ";
    std::cin >> maxYear;

    Algorithms<Dump>::removeIf(dumps, [maxYear](const Dump& d) {
        return d.getYear() <= maxYear;
        });

    std::cout << YELLOW << "Удалены самосвалы, выпущенные до или в " << maxYear << " год." << RESET << std::endl;
}

void DumpMenu::filterDumps() const {
    Stack<Dump> filteredDumps = Algorithms<Dump>::filter(dumps, [](const Dump& d) {
        int minLoad;
        std::cout << "Введите минимальную грузоподъемность для фильтрации: ";
        std::cin >> minLoad;
        return d.getBedWidth() >= minLoad;
        });

    if (filteredDumps.isEmpty()) {
        std::cout << RED << "Нет самосвалов, удовлетворяющих фильтру." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "Отфильтрованные самосвалы:" << RESET << std::endl;
        filteredDumps.forEach([](const Dump& dump) {
            std::cout << dump << std::endl;
            });
    }
}

void DumpMenu::showMenu() {
    int choice;
    do {
        std::cout << "\nМеню Самосвалов:\n";
        std::cout << "1. Добавить Самосвал\n";
        std::cout << "2. Показать все Самосвалы\n";
        std::cout << "3. Удалить последний Самосвал\n";
        std::cout << "4. Загрузить данные с файла\n";
        std::cout << "5. Сохранить данные в файл\n";
        std::cout << "6. Сортировка самосвалов\n";
        std::cout << "7. Удаление по условию\n";
        std::cout << "8. Фильтрация самосвалов\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите опцию: ";

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
        default: std::cout << RED << "Некорректный выбор. Повторите попытку." << RESET << "\n";
        }
    } while (choice != 0);
}

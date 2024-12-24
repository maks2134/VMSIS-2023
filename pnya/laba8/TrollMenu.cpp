#include "TrollMenu.h"
#include "Exception_Vvod.h"
#include "Algorithms.h"

TrollMenu::TrollMenu() : trolls() {}

void TrollMenu::addTroll() {
    try {
        Troll newTroll;
        std::cin >> newTroll;
        trolls.insert({ newTroll.getElectricPower(), newTroll });
        std::cout << YELLOW << "Троллейбус добавлен." << std::endl;
    }
    catch (const Exception_Vvod& e) {
        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Неизвестная ошибка: " << e.what() << std::endl;
    }
}

void TrollMenu::displayTrolls() const {
    if (trolls.empty()) {
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

    for (const auto& pair : trolls) {
        std::cout << pair.second << std::endl;
    }
}

void TrollMenu::removeTroll() {
    if (trolls.empty()) {
        std::cout << RED << "Нет троллейбусов для удаления." << RESET << std::endl;
    }
    else {
        auto it = trolls.begin();
        std::cout << YELLOW << "Удалён троллейбус: " << it->second << RESET << std::endl;
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
        std::cout << "Введите минимальную электро-мощность для поиска: ";
        std::cin >> minPower;

        auto it = trolls.lower_bound(minPower);
        if (it != trolls.end()) {
            std::cout << YELLOW << "Найденный троллейбус:" << std::endl;
            std::cout << it->second << RESET << std::endl;
        }
        else {
            std::cout << RED << "Троллейбус не найден." << RESET << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Ошибка: " << e.what() << RESET << std::endl;
    }
}

void TrollMenu::sortTrolls() {
    // multimap автоматически сортирует элементы по ключу, так что сортировка не требуется
    std::cout << YELLOW << "Троллейбусы отсортированы по электро-мощности (по возрастанию)." << RESET << std::endl;
}

void TrollMenu::removeByCondition() {
    int maxYear;
    std::cout << "Введите максимальный год выпуска для удаления: ";
    std::cin >> maxYear;

    for (auto it = trolls.begin(); it != trolls.end(); ) {
        if (it->second.getYear() <= maxYear) {
            it = trolls.erase(it);
        }
        else {
            ++it;
        }
    }

    std::cout << YELLOW << "Удалены троллейбусы, выпущенные до или в " << maxYear << " год." << RESET << std::endl;
}

void TrollMenu::filterTrolls() const {
    int minSeats;
    std::cout << "Введите минимальное количество мест для фильтрации: ";
    std::cin >> minSeats;

    std::multimap<int, Troll> filteredTrolls;
    for (const auto& pair : trolls) {
        if (pair.second.getSeatsNumber() >= minSeats) {
            filteredTrolls.insert(pair);
        }
    }

    if (filteredTrolls.empty()) {
        std::cout << RED << "Нет троллейбусов, удовлетворяющих фильтру." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "Отфильтрованные троллейбусы:" << RESET << std::endl;
        for (const auto& pair : filteredTrolls) {
            std::cout << pair.second << std::endl;
        }
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
        std::cout << "4. Сохранить данные в файл\n";
        std::cout << "5. Загрузить данные c файла\n";
        std::cout << "6. Поиск троллейбуса\n";
        std::cout << "7. Сортировка троллейбусов\n";
        std::cout << "8. Удаление по условию\n";
        std::cout << "9. Фильтрация троллейбусов\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите опцию: ";

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
        default: std::cout << RED << "Некорректный выбор. Повторите попытку." << RESET << "\n";
        }
    } while (choice != 0);
}

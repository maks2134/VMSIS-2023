//#include "BusMenu.h"
//#include "BusFile.h"
//#include "Exception_Vvod.h"
//
//BusMenu::BusMenu() : buses() {}
//
//void BusMenu::addBus() {
//    try {
//        Bus newBus;
//        std::cin >> newBus;
//        buses.push(newBus);
//        std::cout << "Автобус успешно добавлен!" << std::endl;
//    }
//    catch (const Exception_Vvod& e) {
//        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Неизвестная ошибка: " << e.what() << std::endl;
//    }
//}
//
//void BusMenu::displayBuses() const {
//    if (buses.isEmpty()) {
//        std::cout << RED << "Нет данных для автобусов." << RESET << std::endl;
//        return;
//    }
//
//    std::cout << std::left << std::setw(15) << "Компания"
//        << std::setw(15) << "Модель"
//        << std::setw(10) << "Год"
//        << std::setw(15) << "Мест"
//        << std::setw(15) << "Тип кузова"
//        << std::setw(15) << "Маршрут (км)" << std::endl;
//
//    std::cout << std::string(85, '-') << "\n";
//
//    buses.forEach([](const Bus& bus) {
//        std::cout << bus << std::endl;
//        });
//}
//
//void BusMenu::removeBus() {
//    if (buses.isEmpty()) {
//        std::cout << RED << "Нет автобусов для удаления." << RESET << std::endl;
//    }
//    else {
//        std::cout << BLUE << "Удалён автобус: " << buses.top() << RESET << std::endl;
//        buses.pop();
//    }
//}
//
//void BusMenu::saveBusesToFile() {
//    BusFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.txt");
//    busFile.saveToFile(buses);
//}
//
//void BusMenu::loadBusesFromFile() {
//    BusFile busFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.txt");
//    busFile.loadFromFile(buses);
//}
//
//void BusMenu::saveBusesToBinaryFile() {
//    std::ofstream binaryFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.bin", std::ios::binary);
//    if (!binaryFile) {
//        std::cerr << "Ошибка открытия бинарного файла для записи." << std::endl;
//        return;
//    }
//    buses.forEach([&binaryFile](const Bus& bus) {
//        bus.serializeBinary(binaryFile);
//        });
//    binaryFile.close();
//    std::cout << "Данные автобусов успешно сохранены в бинарный файл." << std::endl;
//}
//
//void BusMenu::loadBusesFromBinaryFile() {
//    std::ifstream binaryFile("C:\\Users\\maks2\\source\\repos\\Lab5\\Lab5\\buses.bin", std::ios::binary);
//    if (!binaryFile) {
//        std::cerr << "Ошибка открытия бинарного файла для чтения." << std::endl;
//        return;
//    }
//    while (binaryFile.peek() != EOF) {
//        Bus bus;
//        bus.deserializeBinary(binaryFile);
//        buses.push(bus);
//    }
//    binaryFile.close();
//    std::cout << "Данные автобусов успешно загружены из бинарного файла." << std::endl;
//}
//
//
//void BusMenu::sortBuses() {
//    Algorithms<Bus>::sort(buses, [](const Bus& a, const Bus& b) {
//        return a.getYear() < b.getYear();
//        });
//
//    std::cout << YELLOW << "Автобусы отсортированы по году выпуска (по возрастанию)." << RESET << std::endl;
//}
//
//void BusMenu::removeByCondition() {
//    int maxYear;
//    std::cout << "Введите максимальный год выпуска для удаления: ";
//    std::cin >> maxYear;
//
//    Algorithms<Bus>::removeIf(buses, [maxYear](const Bus& b) {
//        return b.getYear() <= maxYear;
//        });
//
//    std::cout << YELLOW << "Удалены автобусы, выпущенные до или в " << maxYear << " год." << RESET << std::endl;
//}
//
//void BusMenu::countBusesByCondition() const {
//    int minSeats;
//    std::cout << "Введите минимальное количество мест для подсчета: ";
//    std::cin >> minSeats;
//
//    int count = Algorithms<Bus>::countIf(buses, [minSeats](const Bus& b) {
//        return b.getSeatsNumber() >= minSeats;
//        });
//
//    std::cout << YELLOW << "Количество автобусов с количеством мест не менее " << minSeats << ": " << count << RESET << std::endl;
//}
//
//void BusMenu::findBusByCondition() const {
//    try {
//        int year;
//        std::cout << "Введите год выпуска для поиска: ";
//        std::cin >> year;
//
//        Bus foundBus = Algorithms<Bus>::findByCondition(buses, [year](const Bus& b) {
//            return b.getYear() == year;
//            });
//
//        std::cout << YELLOW << "Найден автобус: " << foundBus << RESET << std::endl;
//    }
//    catch (const std::runtime_error& e) {
//        std::cerr << RED << "Ошибка: " << e.what() << RESET << std::endl;
//    }
//}
//
//
//void BusMenu::showMenu() {
//    int choice;
//    do {
//        std::cout << BLUE;
//        std::cout << "\nМеню Автобусов:\n";
//        std::cout << "1. Добавить Автобус\n";
//        std::cout << "2. Показать все Автобусы\n";
//        std::cout << "3. Удалить последний Автобус\n";
//        std::cout << "4. Сохранить информацию о автобусах в текстовый файл\n";
//        std::cout << "5. Загрузить автобусы из текстового файла\n";
//        std::cout << "6. Сохранить информацию о автобусах в бинарный файл\n";
//        std::cout << "7. Загрузить автобусы из бинарного файла\n";
//        std::cout << "8. Сортировка автобусов\n";
//        std::cout << "9. Удаление по условию\n";
//        std::cout << "10. Подсчет автобусов по условию\n";
//        std::cout << "11. Найти автобус по условию\n";
//        std::cout << "0. Вернуться в главное меню\n";
//        std::cout << "Выберите опцию: ";
//
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1: addBus(); break;
//        case 2: displayBuses(); break;
//        case 3: removeBus(); break;
//        case 4: saveBusesToFile(); break;
//        case 5: loadBusesFromFile(); break;
//        case 6: saveBusesToBinaryFile(); break;
//        case 7: loadBusesFromBinaryFile(); break;
//        case 8: sortBuses(); break;
//        case 9: removeByCondition(); break;
//        case 10: countBusesByCondition(); break;
//        case 11: findBusByCondition(); break;
//        case 0: break;
//        default: std::cout << RED << "Некорректный выбор. Повторите попытку." << RESET << "\n";
//        }
//    } while (choice != 0);
//}
//
//

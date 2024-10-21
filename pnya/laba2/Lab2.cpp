#include <iostream>
#include "Array.h"

void printMenu() {
    std::cout << "Меню:\n";
    std::cout << "1. Создать массив чисел\n";
    std::cout << "2. Создать массив строк\n";
    std::cout << "3. Вывести массив\n";
    std::cout << "4. Сложить два массива\n";
    std::cout << "5. Вычесть два массива\n";
    std::cout << "6. Добавить строку к массиву строк\n";
    std::cout << "7. Выйти\n";
    std::cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Array intArray1, intArray2, intArrayResult;
    Array strArray1, strArray2, strArrayResult;
    bool intArrayCreated = false, strArrayCreated = false;

    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            size_t size;
            std::cout << "Введите размер массива чисел: ";
            std::cin >> size;
            intArray1 = Array(size);
            std::cout << "Введите элементы массива: ";
            std::cin >> intArray1;
            intArrayCreated = true;
            break;
        }
        case 2: {
            size_t size;
            std::cout << "Введите размер массива строк: ";
            std::cin >> size;
            strArray1 = Array(size, true);
            std::cout << "Введите элементы массива: ";
            std::cin >> strArray1;
            strArrayCreated = true;
            break;
        }
        case 3: {
            if (intArrayCreated) {
                std::cout << "Массив чисел: " << intArray1 << std::endl;
            }
            if (strArrayCreated) {
                std::cout << "Массив строк: " << strArray1 << std::endl;
            }
            break;
        }
        case 4: {
            if (intArrayCreated) {
                size_t size;
                std::cout << "Введите размер второго массива чисел: ";
                std::cin >> size;
                intArray2 = Array(size);
                std::cout << "Введите элементы второго массива: ";
                std::cin >> intArray2;
                intArrayResult = intArray1 + intArray2;
                std::cout << "Результат сложения: " << intArrayResult << std::endl;
            }
            if (strArrayCreated) {
                size_t size;
                std::cout << "Введите размер второго массива строк: ";
                std::cin >> size;
                strArray2 = Array(size, true);
                std::cout << "Введите элементы второго массива: ";
                std::cin >> strArray2;
                strArrayResult = strArray1 + strArray2;
                std::cout << "Результат сложения: " << strArrayResult << std::endl;
            }
            break;
        }
        case 5: {
            if (intArrayCreated) {
                size_t size;
                std::cout << "Введите размер второго массива чисел: ";
                std::cin >> size;
                intArray2 = Array(size);
                std::cout << "Введите элементы второго массива: ";
                std::cin >> intArray2;
                intArrayResult = intArray1 - intArray2;
                std::cout << "Результат вычитания: " << intArrayResult << std::endl;
            }
            else {
                std::cout << "Операция вычитания не поддерживается для строковых массивов.\n";
            }
            break;
        }
        case 6: {
            if (strArrayCreated) {
                std::string str;
                std::cout << "Введите строку для добавления: ";
                std::cin >> str;
                strArrayResult = strArray1 + str;
                std::cout << "Результат добавления строки: " << strArrayResult << std::endl;
            }
            break;
        }
        case 7: {
            std::cout << "Выход...\n";
            return 0;
        }
        default: {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    }

    return 0;
}
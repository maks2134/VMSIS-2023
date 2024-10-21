#include "Menu.h"
#include "Array.h"
#include <iostream>
#include <windows.h>

// Функция для вывода меню на экран.
void printMenu() {
    std::cout << "\n====================\n";
    std::cout << "         МЕНЮ\n";
    std::cout << "====================\n";
    std::cout << "1. Добавить число ко всем элементам\n";
    std::cout << "2. Вычесть число из всех элементов\n";
    std::cout << "3. Добавить другой объект Array\n";
    std::cout << "4. Вычесть другой объект Array\n";
    std::cout << "0. Выход\n";
    std::cout << "====================\n";
    std::cout << "Выберите действие: ";
}

// Функция для выбора конструктора и создания объекта Array.
Array createArray() {
    std::cout << "\nВыберите конструктор для создания объекта Array:\n";
    std::cout << "1. Пустой конструктор\n";
    std::cout << "2. Конструктор с размером\n";
    std::cout << "3. Конструктор с массивом\n";
    std::cout << "Ваш выбор: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            return Array(); // Пустой конструктор.
        case 2: {
            int size;
            std::cout << "Введите размер: ";
            std::cin >> size;
            return Array(size); // Конструктор с размером.
        }
        case 3: {
            int size;
            std::cout << "Введите размер массива: ";
            std::cin >> size;
            int* arr = new int[size];
            std::cout << "Введите элементы массива:\n";
            for (int i = 0; i < size; ++i) {
                std::cin >> arr[i];
            }
            Array newArr(arr, size); // Конструктор с существующим массивом.
            delete[] arr; // Освобождаем временный массив.
            return newArr;
        }
        default:
            std::cout << "Неверный выбор, создается пустой массив.\n";
            return Array(); // Пустой конструктор по умолчанию.
    }
}

// Функция для обработки операций в меню.
void runMenu() {
    SetConsoleOutputCP(CP_UTF8);
    int choice;

    do {
        Array newarr = createArray(); // Создание нового объекта Array.

        do {
            printMenu(); // Вывод меню.
            std::cin >> choice; // Получение выбора пользователя.

            switch (choice) {
                case 1: {
                    int value;
                    std::cout << "Введите число: ";
                    std::cin >> value;
                    newarr.add(value); // Добавить число ко всем элементам.
                    break;
                }
                case 2: {
                    int value;
                    std::cout << "Введите число: ";
                    std::cin >> value;
                    newarr.sub(value); // Вычесть число из всех элементов.
                    break;
                }
                case 3: {
                    Array anotherArr = createArray(); // Создание другого объекта Array.
                    newarr.add(anotherArr); // Добавить другой объект Array.
                    break;
                }
                case 4: {
                    Array anotherArr = createArray(); // Создание другого объекта Array.
                    newarr.sub(anotherArr); // Вычесть другой объект Array.
                    break;
                }
                case 0:
                    std::cout << "Выход из текущего объекта.\n"; // Выход из текущих операций.
                    break;
                default:
                    std::cout << "Неверный выбор, попробуйте снова.\n"; // Обработка неверного выбора.
            }

        } while (choice != 0); // Повторять, пока пользователь не выберет выход.

        std::cout << "Хотите начать заново? (1 - Да, 0 - Нет): ";
        std::cin >> choice; // Спросить, хочет ли пользователь начать заново.

    } while (choice != 0); // Повторять весь процесс меню, если пользователь хочет начать снова.

    std::cout << "Выход из программы.\n"; // Выход из программы.
}
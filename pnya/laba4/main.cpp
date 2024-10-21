#include <iostream>
#include "Stack.h"
#include <windows.h>

void displayMenu() {
    std::cout << "=========================\n";
    std::cout << "         МЕНЮ           \n";
    std::cout << "=========================\n";
    std::cout << "1. Добавить элемент\n";
    std::cout << "2. Удалить элемент\n";
    std::cout << "3. Показать верхний элемент\n";
    std::cout << "4. Проверка на пустоту\n";
    std::cout << "5. Выход\n";
    std::cout << "=========================\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Stack<int> stack; // Создание стека для целых чисел
    int choice, value;

    while (true) {
        displayMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Добавить элемент
                std::cout << "Введите элемент: ";
                std::cin >> value;
                try {
                    stack.push(value);
                    std::cout << "Элемент добавлен.\n";
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;

            case 2: // Удалить элемент
                try {
                    value = stack.pop();
                    std::cout << "Удалён элемент: " << value << '\n';
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;

            case 3: // Показать верхний элемент
                try {
                    value = stack.peek();
                    std::cout << "Верхний элемент: " << value << '\n';
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;

            case 4: // Проверка на пустоту
                if (stack.isEmpty()) {
                    std::cout << "Стек пуст.\n";
                } else {
                    std::cout << "Стек не пуст.\n";
                }
                break;

            case 5: // Выход
                std::cout << "Выход из программы.\n";
                return 0;

            default: // Неверный выбор
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
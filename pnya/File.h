#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include "Contant.h"

template <typename T>
class File {
protected:
    std::string filename; // Имя файла для операций

public:
    // Конструктор, принимающий имя файла
    explicit File(const std::string& filename) : filename(filename) {}

    // Метод сохранения данных в файл
    void saveToFile(const Stack<T>& stack) {
        std::ofstream file(filename, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            std::cerr << "Ошибка: невозможно открыть файл для записи." << std::endl;
            return;
        }

        stack.forEach([&file](const T& item) {
            item.serialize(file); // Используем метод serialize для записи
            file << '\n'; // Добавляем разделитель строк
            });

        file.close();
        std::cout << "Данные успешно сохранены в файл: " << filename << "." << std::endl;
    }

    // Метод загрузки данных из файла
    void loadFromFile(Stack<T>& stack) {
        std::ifstream file(filename, std::ios::in);
        if (!file.is_open()) {
            std::cerr << "Ошибка: невозможно открыть файл для чтения." << std::endl;
            return;
        }

        stack = Stack<T>(); // Очищаем стек перед загрузкой

        T item;
        while (file >> std::ws && !file.eof()) { // Проверяем конец файла и пропускаем пробельные символы
            try {
                item.deserialize(file); // Используем метод deserialize для чтения
                stack.push(item);
            }
            catch (const Exception_Vvod& e) {
                std::cerr << e.what() << std::endl;
                break; // Прерываем цикл при возникновении исключения
            }
        }

        file.close();
        std::cout << "Данные успешно загружены из файла: " << filename << "." << std::endl;
    }

};

#endif // FILE_H

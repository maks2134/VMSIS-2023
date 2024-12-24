#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include "Contant.h"

template <typename T>
class File {
protected:
    std::string filename;

public:
    explicit File(const std::string& filename) : filename(filename) {}

    void saveToFile(const Stack<T>& stack) {
        std::ofstream file(filename, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            std::cerr << "Ошибка загрузки в файл" << std::endl;
            return;
        }

        stack.forEach([&file](const T& item) {
            item.serialize(file);
            file << '\n';
            });
        file.close();
        std::cout << "Файл успешно загружен: " << filename << "." << std::endl;
    }

    void loadFromFile(Stack<T>& stack) {
        std::ifstream file(filename, std::ios::in);
        if (!file.is_open()) {
            std::cerr << "Ошибка загрузки файла." << std::endl;
            return;
        }

        stack = Stack<T>();

        T item;
        while (file >> std::ws && !file.eof()) {
            try {
                item.deserialize(file);
                stack.push(item);
            }
            catch (const Exception_Vvod& e) {
                std::cerr << e.what() << std::endl;
                break;
            }
        }

        file.close();
        std::cout << ": " << filename << "." << std::endl;
    }

    // **Методы для работы с бинарными файлами**
    void saveToBinaryFile(const Stack<T>& stack) {
        std::ofstream file(filename, std::ios::binary | std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            std::cerr << "Ошибка записи в бинарный файл" << std::endl;
            return;
        }

        stack.forEach([&file](const T& item) {
            item.serializeBinary(file);
            });

        file.close();
        std::cout << "Бинарный файл успешно загружен: " << filename << "." << std::endl;
    }

    void loadFromBinaryFile(Stack<T>& stack) {
        std::ifstream file(filename, std::ios::binary | std::ios::in);
        if (!file.is_open()) {
            std::cerr << "Ошибка загрузки бинарного файла." << std::endl;
            return;
        }

        stack = Stack<T>();
        T item;
        while (file.peek() != EOF) {
            try {
                item.deserializeBinary(file);
                stack.push(item);
            }
            catch (const Exception_Vvod& e) {
                std::cerr << e.what() << std::endl;
                break;
            }
        }

        file.close();
        std::cout << "Бинарный файл успешно загружен: " << filename << "." << std::endl;
    }
};

#endif // FILE_H
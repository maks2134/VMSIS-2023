#include "Array.h"

// Конструктор по умолчанию
Array::Array() : intData(nullptr), strData(nullptr), size(0), isStringArray(false) {}

// Конструктор с параметрами
Array::Array(size_t size, bool isStringArray) : size(size), isStringArray(isStringArray) {
    if (isStringArray) {
        strData = new std::string[size](); // Инициализация массива строк
        intData = nullptr;
    }
    else {
        intData = new int[size](); // Инициализация массива целых чисел
        strData = nullptr;
    }
}

// Конструктор копирования
Array::Array(const Array& other) : size(other.size), isStringArray(other.isStringArray) {
    if (isStringArray) {
        strData = new std::string[size];
        for (size_t i = 0; i < size; ++i) {
            strData[i] = other.strData[i]; // Копирование содержимого массива строк
        }
        intData = nullptr;
    }
    else {
        intData = new int[size];
        for (size_t i = 0; i < size; ++i) {
            intData[i] = other.intData[i]; // Копирование содержимого массива целых чисел
        }
        strData = nullptr;
    }
}

// Деструктор
Array::~Array() {
    delete[] intData; // Освобождение памяти для массива целых чисел
    delete[] strData; // Освобождение памяти для массива строк
}

// Оператор присваивания
Array& Array::operator=(const Array& other) {
    if (this == &other) {
        return *this; // Проверка на самоприсваивание
    }

    delete[] intData; // Освобождение памяти
    delete[] strData;

    size = other.size; // Перенос размера
    isStringArray = other.isStringArray; // Перенос типа массива

    if (isStringArray) {
        strData = new std::string[size];
        for (size_t i = 0; i < size; ++i) {
            strData[i] = other.strData[i]; // Копирование содержимого
        }
        intData = nullptr;
    }
    else {
        intData = new int[size];
        for (size_t i = 0; i < size; ++i) {
            intData[i] = other.intData[i]; // Копирование содержимого
        }
        strData = nullptr;
    }

    return *this; // Возврат текущего объекта
}

// Оператор сложения
Array Array::operator+(const Array& other) const {
    if (size != other.size || isStringArray != other.isStringArray) {
        return Array(); // Возврат пустого массива, если размеры или типы не совпадают
    }

    Array result(size, isStringArray); // Создание результирующего массива
    if (isStringArray) {
        for (size_t i = 0; i < size; ++i) {
            result.strData[i] = strData[i] + other.strData[i]; // Сложение строк
        }
    }
    else {
        for (size_t i = 0; i < size; ++i) {
            result.intData[i] = intData[i] + other.intData[i]; // Сложение целых чисел
        }
    }

    return result; // Возврат результирующего массива
}

// Оператор вычитания
Array Array::operator-(const Array& other) const {
    if (size != other.size || isStringArray != other.isStringArray) {
        return Array(); // Возврат пустого массива, если размеры или типы не совпадают
    }

    Array result(size, isStringArray); // Создание результирующего массива
    if (!isStringArray) {
        for (size_t i = 0; i < size; ++i) {
            result.intData[i] = intData[i] - other.intData[i]; // Вычитание целых чисел
        }
    }
    else {
        return Array(); // Возврат пустого массива, так как вычитание строк не поддерживается
    }

    return result; // Возврат результирующего массива
}

// Оператор сложения со строкой
Array Array::operator+(const std::string& str) const {
    if (!isStringArray) {
        return Array(); // Возврат пустого массива, если массив не строковый
    }

    Array result(size, isStringArray); // Создание результирующего массива
    for (size_t i = 0; i < size; ++i) {
        result.strData[i] = strData[i] + str; // Сложение строки с каждым элементом массива
    }

    return result; // Возврат результирующего массива
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Array& array) {
    if (array.isStringArray) {
        for (size_t i = 0; i < array.size; ++i) {
            os << array.strData[i] << " "; // Вывод строк
        }
    }
    else {
        for (size_t i = 0; i < array.size; ++i) {
            os << array.intData[i] << " "; // Вывод целых чисел
        }
    }
    return os; // Возврат потока
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Array& array) {
    if (array.isStringArray) {
        for (size_t i = 0; i < array.size; ++i) {
            is >> array.strData[i]; // Ввод строк
        }
    }
    else {
        for (size_t i = 0; i < array.size; ++i) {
            is >> array.intData[i]; // Ввод целых чисел
        }
    }
    return is; // Возврат потока
}

// Метод установки значения целого числа
void Array::set(size_t index, int value) {
    if (isStringArray || index >= size) {
        return; // Если массив строковый или индекс вне диапазона, ничего не делать
    }
    intData[index] = value; // Установка значения
}

// Метод установки значения строки
void Array::set(size_t index, const std::string& value) {
    if (!isStringArray || index >= size) {
        return; // Если массив не строковый или индекс вне диапазона, ничего не делать
    }
    strData[index] = value; // Установка значения
}

// Метод получения значения целого числа
int Array::getInt(size_t index) const {
    if (isStringArray || index >= size) {
        return 0; // Возврат 0, если массив строковый или индекс вне диапазона
    }
    return intData[index]; // Возврат значения
}

// Метод получения значения строки
std::string Array::getString(size_t index) const {
    if (!isStringArray || index >= size) {
        return ""; // Возврат пустой строки, если массив не строковый или индекс вне диапазона
    }
    return strData[index]; // Возврат значения
}

// Метод для вывода содержимого массива
void Array::print() const {
    if (isStringArray) {
        for (size_t i = 0; i < size; ++i) {
            std::cout << strData[i] << " "; // Вывод строк
        }
    }
    else {
        for (size_t i = 0; i < size; ++i) {
            std::cout << intData[i] << " "; // Вывод целых чисел
        }
    }
    std::cout << std::endl; // Перевод строки
}
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>

class Array {
private:
    int* intData;               // Указатель на массив целых чисел
    std::string* strData;       // Указатель на массив строк
    size_t size;                // Размер массива
    bool isStringArray;         // Флаг, указывающий, является ли массив строковым

public:
    Array();                    // Конструктор по умолчанию
    Array(size_t size, bool isStringArray = false); // Конструктор с параметрами
    Array(const Array& other);  // Конструктор копирования
    ~Array();                   // Деструктор

    Array& operator=(const Array& other); // Оператор присваивания

    Array operator+(const Array& other) const; // Оператор сложения
    Array operator-(const Array& other) const; // Оператор вычитания
    Array operator+(const std::string& str) const; // Оператор сложения со строкой

    friend std::ostream& operator<<(std::ostream& os, const Array& array); // Оператор вывода
    friend std::istream& operator>>(std::istream& is, Array& array); // Оператор ввода

    void set(size_t index, int value); // Метод установки значения для целого числа
    void set(size_t index, const std::string& value); // Метод установки значения для строки
    int getInt(size_t index) const; // Метод получения значения целого числа
    std::string getString(size_t index) const; // Метод получения значения строки

    void print() const; // Метод для вывода содержимого массива
};

#endif // ARRAY_H
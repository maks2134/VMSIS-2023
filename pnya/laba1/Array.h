#ifndef LABA1_ARRAY_H
#define LABA1_ARRAY_H
#include <iostream>
#include <limits>
#include <string>

class Array {
private:
    int n; // Количество элементов в массиве.
    int* arr; // Указатель на массив.

    int static getValidInt(const std::string& prompt, bool positiveOnly); // Функция для получения корректного ввода.
    void static Print(); // Функция для вывода массива.

public:
    Array(); // Конструктор по умолчанию.
    Array(int n); // Конструктор с размером.
    Array(const Array& other); // Конструктор копирования.
    Array(const int* arr, int n); // Конструктор с существующим массивом.

    void add(int a); // Добавить число ко всем элементам.
    void add(const Array& Arr); // Добавить элементы другого объекта Array.

    void sub(int a); // Вычесть число из всех элементов.
    void sub(const Array& Arr); // Вычесть элементы другого объекта Array.

    ~Array(); // Деструктор.
};

#endif
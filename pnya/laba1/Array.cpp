#include "Array.h"

// Функция для получения корректного целого числа от пользователя.
int Array::getValidInt(const std::string& prompt, bool positiveOnly) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || (positiveOnly && value <= 0)) {
            std::cin.clear(); // Очистка состояния ошибки ввода.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорировать неверный ввод.
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
        } else {
            return value; // Вернуть корректный ввод.
        }
    }
}

// Вывод элементов массива.
void Array::Print() {
    std::cout << "Элементы объекта Array:\n[ ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " "; // Вывод каждого элемента.
    }
    std::cout << "]" << std::endl;
}

// Конструктор по умолчанию для инициализации пустого массива.
Array::Array() {
    this->n = 0;
    this->arr = nullptr;
}

// Конструктор с размером.
Array::Array(int n) {
    this->n = n;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = getValidInt("Введите элемент: ", false); // Получение каждого элемента.
    }
}

// Конструктор копирования.
Array::Array(const Array& other) : n(other.n) {
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
}

// Конструктор с существующим массивом.
Array::Array(const int* inputArr, int n) : n(n) {
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = inputArr[i];
    }
}

// Добавить значение ко всем элементам массива.
void Array::add(int a) {
    for (int i = 0; i < n; ++i) {
        arr[i] += a;
    }
}

// Добавить элементы другого объекта Array к этому массиву.
void Array::add(const Array& Arr) {
    for (int i = 0; i < n && i < Arr.n; ++i) {
        arr[i] += Arr.arr[i];
    }
}

// Вычесть значение из всех элементов массива.
void Array::sub(int a) {
    for (int i = 0; i < n; ++i) {
        arr[i] -= a;
    }
}

// Вычесть элементы другого объекта Array из этого массива.
void Array::sub(const Array& Arr) {
    for (int i = 0; i < n && i < Arr.n; ++i) {
        arr[i] -= Arr.arr[i];
    }
}

// Деструктор для очистки выделенной памяти.
Array::~Array() {
    Print(); // Печать массива перед удалением.
    delete[] arr; // Освобождение памяти.
}
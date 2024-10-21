#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data;           // Массив для хранения элементов стека
    int capacity;      // Вместимость стека
    int top;           // Индекс верхнего элемента

public:
    Stack(int size = 10);   // Конструктор
    ~Stack();                // Деструктор

    void push(const T& item); // Добавление элемента
    T pop();                  // Удаление элемента
    T peek() const;          // Получение верхнего элемента
    bool isEmpty() const;    // Проверка на пустоту
    int size() const;        // Получение размера стека
};

#endif // STACK_H
#include "Stack.h"

// Конструктор
template <typename T>
Stack<T>::Stack(int size) : capacity(size), top(-1) {
    data = new T[capacity];
}

// Деструктор
template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

// Добавление элемента в стек
template <typename T>
void Stack<T>::push(const T& item) {
    if (top == capacity - 1) {
        throw std::overflow_error("Стек переполнен");
    }
    data[++top] = item;
}

// Удаление элемента из стека
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст");
    }
    return data[top--];
}

// Получение верхнего элемента
template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст");
    }
    return data[top];
}

// Проверка на пустоту
template <typename T>
bool Stack<T>::isEmpty() const {
    return top == -1;
}

// Получение размера стека
template <typename T>
int Stack<T>::size() const {
    return top + 1;
}

template class Stack<int>; // Пример инстанцирования для целочисленного типа
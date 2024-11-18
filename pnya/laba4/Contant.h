#pragma once
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();

    void push(const T& item);
    T pop();
    bool isEmpty() const;
    bool isFull() const;

    // Iterator support using pointers
    T* begin() const { return data; }
    T* end() const { return data + top + 1; }
};

template <typename T>
Stack<T>::Stack(int size) : capacity(size), top(-1) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
void Stack<T>::push(const T& item) {
    if (isFull()) {
        throw std::overflow_error("Stack overflow");
    }
    data[++top] = item;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack underflow");
    }
    return data[top--];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull() const {
    return top == capacity - 1;
}
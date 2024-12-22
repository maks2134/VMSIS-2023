#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <functional>

template <typename T>
class Stack {
private:
    // Вложенный класс Node
    class Node {
    private:
        T data;
        Node* next;

    public:
        // Конструктор для инициализации узла
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}

        // Геттеры для доступа к данным и следующему узлу
        T getData() const { return data; }
        Node* getNext() const { return next; }

        // Класс Stack объявляется дружественным для доступа к закрытым полям
        friend class Stack<T>;
    };

    Node* topNode; // Указатель на вершину стека

public:
    // Конструктор по умолчанию
    Stack() : topNode(nullptr) {}

    // Деструктор для освобождения памяти
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Метод добавления нового элемента в стек
    void push(const T& data) {
        Node* newNode = new Node(data, topNode);
        topNode = newNode;
    }

    // Метод удаления элемента с вершины стека
    void pop() {
        if (isEmpty()) {
            std::cout << "Стек пуст!" << std::endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Метод получения элемента на вершине стека
    T top() const {
        if (isEmpty()) {
            throw std::runtime_error("Стек пуст!");
        }
        return topNode->data;
    }

    // Метод проверки, пуст ли стек
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Новый метод обхода
    void forEach(std::function<void(const T&)> action) const {
        Node* current = topNode;
        while (current) {
            action(current->data);
            current = current->next;
        }
    }
};

#endif
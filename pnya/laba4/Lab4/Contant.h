#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <functional> 

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Стек пуст!" << std::endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const {
        if (isEmpty()) {
            throw std::runtime_error("Стек пуст!");
        }
        return topNode->data;
    }

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

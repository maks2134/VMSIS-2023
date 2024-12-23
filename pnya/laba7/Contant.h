#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

template <typename T>
class Stack {
private:
    class Node {
    private:
        T data;
        Node* next;

    public:
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
        T getData() const { return data; }
        Node* getNext() const { return next; }
        friend class Stack<T>;
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
        Node* newNode = new Node(data, topNode);
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
    void clear() {
        while (!isEmpty()) {
            pop();
        }
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

    void forEach(std::function<void(const T&)> action) const {
        Node* current = topNode;
        while (current) {
            action(current->data);
            current = current->next;
        }
    }

    // Итератор для стека
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() const { return current->data; }
        Iterator& operator++() {
            current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() const { return Iterator(topNode); }
    Iterator end() const { return Iterator(nullptr); }

   
};

#endif

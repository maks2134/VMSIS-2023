#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <functional>

template <typename T>
class Stack {
private:
    // ��������� ����� Node
    class Node {
    private:
        T data;
        Node* next;

    public:
        // ����������� ��� ������������� ����
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}

        // ������� ��� ������� � ������ � ���������� ����
        T getData() const { return data; }
        Node* getNext() const { return next; }

        // ����� Stack ����������� ������������� ��� ������� � �������� �����
        friend class Stack<T>;
    };

    Node* topNode; // ��������� �� ������� �����

public:
    // ����������� �� ���������
    Stack() : topNode(nullptr) {}

    // ���������� ��� ������������ ������
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // ����� ���������� ������ �������� � ����
    void push(const T& data) {
        Node* newNode = new Node(data, topNode);
        topNode = newNode;
    }

    // ����� �������� �������� � ������� �����
    void pop() {
        if (isEmpty()) {
            std::cout << "���� ����!" << std::endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // ����� ��������� �������� �� ������� �����
    T top() const {
        if (isEmpty()) {
            throw std::runtime_error("���� ����!");
        }
        return topNode->data;
    }

    // ����� ��������, ���� �� ����
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // ����� ����� ������
    void forEach(std::function<void(const T&)> action) const {
        Node* current = topNode;
        while (current) {
            action(current->data);
            current = current->next;
        }
    }
};

#endif
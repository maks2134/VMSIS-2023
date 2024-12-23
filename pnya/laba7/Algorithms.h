#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Contant.h"
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class Algorithms {
public:
    // ����� �������� �� �������
    static T findByCondition(const Stack<T>& stack, std::function<bool(const T&)> condition) {
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (condition(*it)) {
                return *it;
            }
        }
        throw std::runtime_error("�������, ��������������� �������, �� ������.");
    }

    // ���������� ��������� ���������� �� ��������� ��������
    static void sort(Stack<T>& stack, std::function<bool(const T&, const T&)> comparator) {
        std::vector<T> elements;

        // ��������� �������� �� ���������� � ������
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            elements.push_back(*it);
        }

        // ��������� ������
        std::sort(elements.begin(), elements.end(), comparator);

        // �������������� ���������
        stack.clear(); // ������� ���������
        for (const T& elem : elements) {
            stack.push(elem); // ��������� ��������������� �������� �������
        }
    }

    // �������� ��������� �� �������
    static void removeIf(Stack<T>& stack, std::function<bool(const T&)> condition) {
        std::vector<T> elements;

        // ��������� ��������, ������� �� �������� ��� �������, �� ��������� ������
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (!condition(*it)) {
                elements.push_back(*it);
            }
        }

        // �������������� ���������
        stack.clear();
        for (const T& elem : elements) {
            stack.push(elem);
        }
    }

    // ���������� ���������
    static Stack<T> filter(const Stack<T>& stack, std::function<bool(const T&)> condition) {
        Stack<T> filteredStack;

        // ��������� ������ �� ��������, ������� ������������� �������
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (condition(*it)) {
                filteredStack.push(*it);
            }
        }

        return filteredStack;
    }
};

#endif

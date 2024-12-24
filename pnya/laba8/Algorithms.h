#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Contant.h"
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class Algorithms {
public:
    // Поиск элемента по условию
    static T findByCondition(const Stack<T>& stack, std::function<bool(const T&)> condition) {
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (condition(*it)) {
                return *it;
            }
        }
        throw std::runtime_error("Элемент, удовлетворяющий условию, не найден.");
    }

    // Сортировка элементов контейнера по заданному критерию
    static void sort(Stack<T>& stack, std::function<bool(const T&, const T&)> comparator) {
        std::vector<T> elements;

        // Переносим элементы из контейнера в вектор
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            elements.push_back(*it);
        }

        // Сортируем вектор
        std::sort(elements.begin(), elements.end(), comparator);

        // Перезаписываем контейнер
        stack.clear(); // Очищаем контейнер
        for (const T& elem : elements) {
            stack.push(elem); // Добавляем отсортированные элементы обратно
        }
    }

    // Удаление элементов по условию
    static void removeIf(Stack<T>& stack, std::function<bool(const T&)> condition) {
        std::vector<T> elements;

        // Переносим элементы, которые не подходят под условие, во временный вектор
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (!condition(*it)) {
                elements.push_back(*it);
            }
        }

        // Перезаписываем контейнер
        stack.clear();
        for (const T& elem : elements) {
            stack.push(elem);
        }
    }

    // Фильтрация элементов
    static Stack<T> filter(const Stack<T>& stack, std::function<bool(const T&)> condition) {
        Stack<T> filteredStack;

        // Добавляем только те элементы, которые удовлетворяют условию
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (condition(*it)) {
                filteredStack.push(*it);
            }
        }

        return filteredStack;
    }
};

#endif

// Algorithms.h
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>

template <typename TKey, typename TValue>
class Algorithms {
public:
    // Поиск элемента по условию
    static TValue findByCondition(const std::multimap<TKey, TValue>& stack, std::function<bool(const TValue&)> condition) {
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (condition(it->second)) {
                return it->second;
            }
        }
        throw std::runtime_error("Элемент, удовлетворяющий условию, не найден.");
    }

    // Сортировка элементов контейнера по заданному критерию
    static void sort(std::multimap<TKey, TValue>& stack, std::function<bool(const TValue&, const TValue&)> comparator) {
        std::vector<std::pair<TKey, TValue>> elements;

        // Переносим элементы из контейнера в вектор
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            elements.push_back(*it);
        }

        // Сортируем вектор
        std::sort(elements.begin(), elements.end(), [&comparator](const auto& a, const auto& b) {
            return comparator(a.second, b.second);
            });

        // Перезаписываем контейнер
        stack.clear(); // Очищаем контейнер
        for (const auto& elem : elements) {
            stack.insert(elem); // Добавляем отсортированные элементы обратно
        }
    }

    // Удаление элементов по условию
    static void removeIf(std::multimap<TKey, TValue>& stack, std::function<bool(const TValue&)> condition) {
        for (auto it = stack.begin(); it != stack.end(); ) {
            if (condition(it->second)) {
                it = stack.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    // Подсчет элементов, удовлетворяющих условию
    static int countIf(const std::multimap<TKey, TValue>& stack, std::function<bool(const TValue&)> condition) {
        int count = 0;
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (condition(it->second)) {
                ++count;
            }
        }
        return count;
    }
};

#endif

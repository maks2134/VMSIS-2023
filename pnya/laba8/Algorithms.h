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
    // ����� �������� �� �������
    static TValue findByCondition(const std::multimap<TKey, TValue>& stack, std::function<bool(const TValue&)> condition) {
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            if (condition(it->second)) {
                return it->second;
            }
        }
        throw std::runtime_error("�������, ��������������� �������, �� ������.");
    }

    // ���������� ��������� ���������� �� ��������� ��������
    static void sort(std::multimap<TKey, TValue>& stack, std::function<bool(const TValue&, const TValue&)> comparator) {
        std::vector<std::pair<TKey, TValue>> elements;

        // ��������� �������� �� ���������� � ������
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            elements.push_back(*it);
        }

        // ��������� ������
        std::sort(elements.begin(), elements.end(), [&comparator](const auto& a, const auto& b) {
            return comparator(a.second, b.second);
            });

        // �������������� ���������
        stack.clear(); // ������� ���������
        for (const auto& elem : elements) {
            stack.insert(elem); // ��������� ��������������� �������� �������
        }
    }

    // �������� ��������� �� �������
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

    // ������� ���������, ��������������� �������
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

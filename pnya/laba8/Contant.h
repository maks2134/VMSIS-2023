#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <functional>
#include <map>

template <typename TKey, typename TValue>
class MultiMap {
private:
    std::multimap<TKey, TValue> mmap;

public:
    MultiMap() = default;

    ~MultiMap() = default;

    void push(const TKey& key, const TValue& value) {
        mmap.insert({ key, value });
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Стек пуст!" << std::endl;
            return;
        }
        auto it = mmap.begin();
        mmap.erase(it);
    }

    void clear() {
        mmap.clear();
    }

    TValue top() const {
        if (isEmpty()) {
            throw std::runtime_error("Стек пуст!");
        }
        return mmap.begin()->second;
    }

    bool isEmpty() const {
        return mmap.empty();
    }

    void forEach(std::function<void(const TKey&, const TValue&)> action) const {
        for (const auto& pair : mmap) {
            action(pair.first, pair.second);
        }
    }

    // Итератор для multimap
    using Iterator = typename std::multimap<TKey, TValue>::iterator;
    using ConstIterator = typename std::multimap<TKey, TValue>::const_iterator;

    Iterator begin() { return mmap.begin(); }
    Iterator end() { return mmap.end(); }
    ConstIterator begin() const { return mmap.begin(); }
    ConstIterator end() const { return mmap.end(); }
};

#endif

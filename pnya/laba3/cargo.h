#ifndef LAB3_CARGO_H
#define LAB3_CARGO_H
#include "Auto.h"

class Cargo : public Auto {
private:
    double loadCapacity;
    int numberOfAxles;

public:
    // Конструктор по умолчанию
    Cargo();
    // Параметризированный конструктор
    Cargo(const std::string &company, const std::string &modal, int year, double loadCapacity, int numberOfAxles);

    // Геттеры и сеттеры
    double getLoadCapacity() const;
    int getNumberOfAxles() const;

    void setLoadCapacity(double loadCapacity);
    void setNumberOfAxles(int numberOfAxles);

    // Перегрузка операторов
    friend std::istream& operator>>(std::istream &input, Cargo &cargoObj);
    friend std::ostream& operator<<(std::ostream &output, const Cargo &cargoObj);
};

#endif //LAB3_CARGO_H
#include "Dump.h"

#include "Dump.h"
#include <iostream>

// Конструктор по умолчанию
Dump::Dump() : Cargo(), bedLength(0.0), bedWidth(0.0) {}

// Параметризированный конструктор
Dump::Dump(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles, double bedLength, double bedWidth)
    : Cargo(company, modal, year, loadCapacity, numberOfAxles), bedLength(bedLength), bedWidth(bedWidth) {}

// Геттеры
double Dump::getBedLength() const {
    return bedLength;
}

double Dump::getBedWidth() const {
    return bedWidth;
}

// Сеттеры
void Dump::setBedLength(double bedLength) {
    this->bedLength = bedLength;
}

void Dump::setBedWidth(double bedWidth) {
    this->bedWidth = bedWidth;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& input, Dump& dumpObj) {
    input >> static_cast<Cargo&>(dumpObj); // Чтение атрибутов базового класса
    std::cout << "Введите длину кузова (в метрах): ";
    input >> dumpObj.bedLength;
    std::cout << "Введите ширину кузова (в метрах): ";
    input >> dumpObj.bedWidth;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Dump& dumpObj) {
    output << static_cast<const Cargo&>(dumpObj); // Вывод атрибутов базового класса
    output << ", Длина кузова: " << dumpObj.bedLength << " м, Ширина кузова: " << dumpObj.bedWidth << " м";
    return output;
}
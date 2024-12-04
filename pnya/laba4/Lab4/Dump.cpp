#include "Dump.h"
#include <iomanip>

// Конструктор по умолчанию
Dump::Dump() : Cargo(), bedWidth(0.0) {}

// Параметризированный конструктор
Dump::Dump(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles, double bedWidth)
    : Cargo(company, modal, year, loadCapacity, numberOfAxles), bedWidth(bedWidth) {
}

double Dump::getBedWidth() const {
    return bedWidth;
}

void Dump::setBedWidth(double bedWidth) {
    this->bedWidth = bedWidth;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& input, Dump& dumpObj) {
    input >> static_cast<Cargo&>(dumpObj);
    std::cout << "Введите ширину кузова (в метрах): ";
    input >> dumpObj.bedWidth;
    return input;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& output, const Dump& dumpObj) {
    output << static_cast<const Cargo&>(dumpObj); // Вывод базового класса
    output << std::setw(15) << dumpObj.bedWidth;
    return output;
}

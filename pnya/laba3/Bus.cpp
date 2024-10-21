#include "Bus.h"
#include <iostream>

// Конструктор по умолчанию
Bus::Bus() : Passanger(), marKM(0) {}

// Параметризированный конструктор
Bus::Bus(const std::string &company, const std::string &modal, int year, int seatsNumber, std::string bodyType, int marKM)
        : Passanger(company, modal, year, seatsNumber, bodyType), marKM(marKM) {}

// Геттеры
int Bus::getMarchuteKm() const {
    return marKM;
}

// Сеттеры
void Bus::setMarchuteKm(int marKM) const {
    this->marKM = marKM;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream &input, Dump &dumpObj) {
    input >> static_cast<Cargo&>(dumpObj); // Чтение атрибутов базового класса
    std::cout << "Введите длину кузова (в метрах): ";
    input >> dumpObj.bedLength;
    std::cout << "Введите ширину кузова (в метрах): ";
    input >> dumpObj.bedWidth;
    return input;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream &output, const Dump &dumpObj) {
    output << static_cast<const Cargo&>(dumpObj); // Вывод атрибутов базового класса
    output << ", Длина кузова: " << dumpObj.bedLength << " м, Ширина кузова: " << dumpObj.bedWidth << " м";
    return output;
}
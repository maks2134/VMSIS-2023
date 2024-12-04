#include "passanger.h"
#include <iostream>
#include <iomanip>
#include "Exception_Vvod.h"

Passanger::Passanger() : Auto(), seatsNumber(0), bodyType("") {}

Passanger::Passanger(const std::string& company, const std::string& modal, int year, int seatsNumber, const std::string& bodyType)
    : Auto(company, modal, year), seatsNumber(seatsNumber), bodyType(bodyType) {
}

int Passanger::getSeatsNumber() const {
    return seatsNumber;
}

std::string Passanger::getBodyType() const {
    return bodyType;
}

void Passanger::setSeatsNumber(int seatsNumber) {
    this->seatsNumber = seatsNumber;
}

void Passanger::setBodyType(std::string bodyType) {
    this->bodyType = bodyType;
}

std::istream& operator>>(std::istream& input, Passanger& passangerObj) {
    try {
        input >> static_cast<Auto&>(passangerObj); // Ввод данных базового класса Auto
    }
    catch (const Exception& e) {
        throw; // Перебрасываем исключение
    }

    std::cout << "Введите количество мест в машине: ";
    if (!(input >> passangerObj.seatsNumber) || passangerObj.seatsNumber <= 0) {
        throw Exception_Vvod("Некорректное количество мест.");
    }

    std::cout << "Введите тип кузова: ";
    if (!(input >> passangerObj.bodyType) || passangerObj.bodyType.empty()) {
        throw Exception_Vvod("Некорректный тип кузова.");
    }

    return input;
}   

std::ostream& operator<<(std::ostream& output, const Passanger& passangerObj) {
    output << static_cast<const Auto&>(passangerObj); // Вывод базового класса
    output << std::setw(15) << passangerObj.seatsNumber
        << std::setw(15) << passangerObj.bodyType;
    return output;
}
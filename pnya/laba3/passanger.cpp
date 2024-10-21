#include "passanger.h"
#include <iostream>

Passanger::Passanger() : Auto(), seatsNumber(0), bodyType(nullptr) {}

Passanger::Passanger(const std::string &company, const std::string &modal, int year, int seatsNumber, const std::string& bodyType)
        : Auto(company, modal, year), seatsNumber(seatsNumber), bodyType(bodyType) {}

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

std::istream& operator>>(std::istream &input, Passanger &passangerObj) {
    input >> static_cast<Auto&>(passangerObj);
    std::cout << "Введите колличество мест в машине: ";
    input >> passangerObj.seatsNumber;
    std::cout << "Введите тип кузова: ";
    input >> passangerObj.bodyType;
    return input;
}

std::ostream& operator<<(std::ostream &output, const Passanger &passangerObj) {
    output << static_cast<const Auto&>(passangerObj);
    output << ", колличество мест в машине: " << passangerObj.seatsNumber << " тон, тип кузова: " << passangerObj.bodyType;
    return output;
}
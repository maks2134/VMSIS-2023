#include "passanger.h"
#include <iostream>
#include <iomanip>
#include <fstream>
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

void Passanger::serialize(std::ofstream& output) const {
    Auto::serialize(output); // Сериализация полей базового класса
    output << ' ' << seatsNumber << ' ' << bodyType;
}

void Passanger::deserialize(std::ifstream& input) {
    Auto::deserialize(input); // Десериализация полей базового класса
    if (!(input >> seatsNumber) || !(input >> bodyType)) {
        throw Exception_Vvod("Ошибка при чтении данных Passanger.");
    }
}

void Passanger::deserializeBinary(std::ifstream& input) {
    Auto::deserializeBinary(input); // Десериализация полей базового класса в бинарном формате
    input.read(reinterpret_cast<char*>(&seatsNumber), sizeof(seatsNumber));
    std::getline(input, bodyType, '\0');
}

void Passanger::serializeBinary(std::ofstream& output) const {
    Auto::serializeBinary(output); // Сериализация полей базового класса
    output.write(reinterpret_cast<const char*>(&seatsNumber), sizeof(seatsNumber));
    output.write(bodyType.c_str(), bodyType.size() + 1); // Запись строки с завершающим нулем
}


std::istream& operator>>(std::istream& input, Passanger& passangerObj) {
    input >> static_cast<Auto&>(passangerObj);

    do {
        std::cout << "Введите количество мест в машине: ";
        if (input >> passangerObj.seatsNumber && passangerObj.seatsNumber > 0) {
            break;
        }
        std::cerr << "Некорректное количество мест. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    do {
        std::cout << "Введите тип кузова: ";
        if (input >> passangerObj.bodyType && !passangerObj.bodyType.empty()) {
            break;
        }
        std::cerr << "Некорректный тип кузова. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    return input;
}

std::ostream& operator<<(std::ostream& output, const Passanger& passangerObj) {
    output << static_cast<const Auto&>(passangerObj); // Вывод базового класса
    output << std::setw(15) << passangerObj.seatsNumber
        << std::setw(15) << passangerObj.bodyType;
    return output;
}

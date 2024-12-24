#include "Cargo.h"
#include <iostream>
#include <iomanip>
#include "Exception_Vvod.h"
#include <sstream> // Include for stringstream
#include <fstream>

Cargo::Cargo() : Auto(), loadCapacity(0.0), numberOfAxles(0) {}

Cargo::Cargo(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles)
    : Auto(company, modal, year), loadCapacity(loadCapacity), numberOfAxles(numberOfAxles) {
}

double Cargo::getLoadCapacity() const {
    return loadCapacity;
}

int Cargo::getNumberOfAxles() const {
    return numberOfAxles;
}

void Cargo::setLoadCapacity(double loadCapacity) {
    this->loadCapacity = loadCapacity;
}

void Cargo::setNumberOfAxles(int numberOfAxles) {
    this->numberOfAxles = numberOfAxles;
}

void Cargo::serialize(std::ofstream& output) const {
    Cargo::serialize(output); // Сериализация полей базового класса
    output << ' ' << loadCapacity << ' ' << numberOfAxles;
}

void Cargo::deserialize(std::ifstream& input) {
    Cargo::deserialize(input); // Десериализация полей базового класса
    if (!(input >> numberOfAxles >> loadCapacity)) {
        throw Exception_Vvod("Ошибка при чтении данных Cargo.");
    }
}

std::istream& operator>>(std::istream& input, Cargo& cargoObj) {
    try {
        input >> static_cast<Auto&>(cargoObj); // Ввод данных базового класса Auto
    }
    catch (const Exception& e) {
        throw; // Перебрасываем исключение
    }

    std::cout << "Введите грузоподъёмность: ";
    if (!(input >> cargoObj.loadCapacity) || cargoObj.loadCapacity <= 0) {
        throw Exception_Vvod("Некорректная грузоподъёмность.");
    }

    std::cout << "Введите количество осей: ";
    if (!(input >> cargoObj.numberOfAxles) || cargoObj.numberOfAxles <= 0) {
        throw Exception_Vvod("Некорректное количество осей.");
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Cargo& cargoObj) {
    output << static_cast<const Auto&>(cargoObj); // Вывод базового класса
    output << std::setw(15) << cargoObj.loadCapacity
        << std::setw(10) << cargoObj.numberOfAxles;
    return output;
}
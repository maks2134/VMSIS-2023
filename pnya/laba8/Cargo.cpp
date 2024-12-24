// В файл реализации Cargo.cpp добавим определения методов для работы с бинарными файлами
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
    Auto::serialize(output); // Сериализация полей базового класса
    output << ' ' << loadCapacity << ' ' << numberOfAxles;
}

void Cargo::deserialize(std::ifstream& input) {
    Auto::deserialize(input); // Десериализация полей базового класса
    if (!(input >> numberOfAxles >> loadCapacity)) {
        throw Exception_Vvod("Ошибка при чтении данных Cargo.");
    }
}

void Cargo::serializeBinary(std::ofstream& output) const {
    Auto::serializeBinary(output); // Сериализация полей базового класса в бинарный файл
    output.write(reinterpret_cast<const char*>(&loadCapacity), sizeof(loadCapacity));
    output.write(reinterpret_cast<const char*>(&numberOfAxles), sizeof(numberOfAxles));
}

void Cargo::deserializeBinary(std::ifstream& input) {
    Auto::deserializeBinary(input); // Десериализация полей базового класса из бинарного файла
    if (!input.read(reinterpret_cast<char*>(&loadCapacity), sizeof(loadCapacity)) ||
        !input.read(reinterpret_cast<char*>(&numberOfAxles), sizeof(numberOfAxles))) {
        throw Exception_Vvod("Ошибка при чтении данных Cargo из бинарного файла.");
    }
}

std::istream& operator>>(std::istream& input, Cargo& cargoObj) {
    try {
        input >> static_cast<Auto&>(cargoObj); // Ввод данных базового класса Auto
    }
    catch (const Exception& e) {
        throw; // Перебрасываем исключение
    }

    do {
        std::cout << "Введите грузоподъёмность: ";
        if (input >> cargoObj.loadCapacity && cargoObj.loadCapacity > 0) {
            break;
        }
        std::cerr << "Некорректная грузоподъёмность. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    do {
        std::cout << "Введите количество осей: ";
        if (input >> cargoObj.numberOfAxles && cargoObj.numberOfAxles > 0) {
            break;
        }
        std::cerr << "Некорректное количество осей. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    return input;
}

std::ostream& operator<<(std::ostream& output, const Cargo& cargoObj) {
    output << static_cast<const Auto&>(cargoObj); // Вывод базового класса
    output << std::setw(15) << cargoObj.loadCapacity
        << std::setw(10) << cargoObj.numberOfAxles;
    return output;
}


#include "Cargo.h"
#include <iostream>

Cargo::Cargo() : Auto(), loadCapacity(0.0), numberOfAxles(0) {}

Cargo::Cargo(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles)
    : Auto(company, modal, year), loadCapacity(loadCapacity), numberOfAxles(numberOfAxles) {}

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

std::istream& operator>>(std::istream& input, Cargo& cargoObj) {
    input >> static_cast<Auto&>(cargoObj);
    std::cout << "¬ведите грузоподъЄмность: ";
    input >> cargoObj.loadCapacity;
    std::cout << "¬ведите колличество осей: ";
    input >> cargoObj.numberOfAxles;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Cargo& cargoObj) {
    output << static_cast<const Auto&>(cargoObj);
    output << ", грузоподъЄмность: " << cargoObj.loadCapacity << " тон, колличество осей: " << cargoObj.numberOfAxles;
    return output;
}   
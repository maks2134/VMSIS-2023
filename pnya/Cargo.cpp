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
    Cargo::serialize(output); // ������������ ����� �������� ������
    output << ' ' << loadCapacity << ' ' << numberOfAxles;
}

void Cargo::deserialize(std::ifstream& input) {
    Cargo::deserialize(input); // �������������� ����� �������� ������
    if (!(input >> numberOfAxles >> loadCapacity)) {
        throw Exception_Vvod("������ ��� ������ ������ Cargo.");
    }
}

std::istream& operator>>(std::istream& input, Cargo& cargoObj) {
    try {
        input >> static_cast<Auto&>(cargoObj); // ���� ������ �������� ������ Auto
    }
    catch (const Exception& e) {
        throw; // ������������� ����������
    }

    std::cout << "������� ����������������: ";
    if (!(input >> cargoObj.loadCapacity) || cargoObj.loadCapacity <= 0) {
        throw Exception_Vvod("������������ ����������������.");
    }

    std::cout << "������� ���������� ����: ";
    if (!(input >> cargoObj.numberOfAxles) || cargoObj.numberOfAxles <= 0) {
        throw Exception_Vvod("������������ ���������� ����.");
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Cargo& cargoObj) {
    output << static_cast<const Auto&>(cargoObj); // ����� �������� ������
    output << std::setw(15) << cargoObj.loadCapacity
        << std::setw(10) << cargoObj.numberOfAxles;
    return output;
}
// � ���� ���������� Cargo.cpp ������� ����������� ������� ��� ������ � ��������� �������
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
    Auto::serialize(output); // ������������ ����� �������� ������
    output << ' ' << loadCapacity << ' ' << numberOfAxles;
}

void Cargo::deserialize(std::ifstream& input) {
    Auto::deserialize(input); // �������������� ����� �������� ������
    if (!(input >> numberOfAxles >> loadCapacity)) {
        throw Exception_Vvod("������ ��� ������ ������ Cargo.");
    }
}

void Cargo::serializeBinary(std::ofstream& output) const {
    Auto::serializeBinary(output); // ������������ ����� �������� ������ � �������� ����
    output.write(reinterpret_cast<const char*>(&loadCapacity), sizeof(loadCapacity));
    output.write(reinterpret_cast<const char*>(&numberOfAxles), sizeof(numberOfAxles));
}

void Cargo::deserializeBinary(std::ifstream& input) {
    Auto::deserializeBinary(input); // �������������� ����� �������� ������ �� ��������� �����
    if (!input.read(reinterpret_cast<char*>(&loadCapacity), sizeof(loadCapacity)) ||
        !input.read(reinterpret_cast<char*>(&numberOfAxles), sizeof(numberOfAxles))) {
        throw Exception_Vvod("������ ��� ������ ������ Cargo �� ��������� �����.");
    }
}

std::istream& operator>>(std::istream& input, Cargo& cargoObj) {
    try {
        input >> static_cast<Auto&>(cargoObj); // ���� ������ �������� ������ Auto
    }
    catch (const Exception& e) {
        throw; // ������������� ����������
    }

    do {
        std::cout << "������� ����������������: ";
        if (input >> cargoObj.loadCapacity && cargoObj.loadCapacity > 0) {
            break;
        }
        std::cerr << "������������ ����������������. ��������� ����." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    do {
        std::cout << "������� ���������� ����: ";
        if (input >> cargoObj.numberOfAxles && cargoObj.numberOfAxles > 0) {
            break;
        }
        std::cerr << "������������ ���������� ����. ��������� ����." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    return input;
}

std::ostream& operator<<(std::ostream& output, const Cargo& cargoObj) {
    output << static_cast<const Auto&>(cargoObj); // ����� �������� ������
    output << std::setw(15) << cargoObj.loadCapacity
        << std::setw(10) << cargoObj.numberOfAxles;
    return output;
}


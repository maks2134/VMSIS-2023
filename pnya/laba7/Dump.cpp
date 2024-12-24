// � ���� ���������� Dump.cpp ������� ����������� ������� ��� ������ � ��������� �������
#include "Dump.h"
#include <iomanip>
#include <fstream>
#include "Exception_Vvod.h"

// ����������� �� ���������
Dump::Dump() : Cargo(), bedWidth(0.0) {}

// ������������������� �����������
Dump::Dump(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles, double bedWidth)
    : Cargo(company, modal, year, loadCapacity, numberOfAxles), bedWidth(bedWidth) {
}

double Dump::getBedWidth() const {
    return bedWidth;
}

void Dump::setBedWidth(double bedWidth) {
    this->bedWidth = bedWidth;
}

void Dump::serialize(std::ofstream& output) const {
    Cargo::serialize(output); // ������������ ����� �������� ������
    output << ' ' << bedWidth;
}

void Dump::deserialize(std::ifstream& input) {
    Cargo::deserialize(input); // �������������� ����� �������� ������
    if (!(input >> bedWidth)) {
        throw Exception_Vvod("������ ��� ������ ������ Dump.");
    }
}

void Dump::serializeBinary(std::ofstream& output) const {
    Cargo::serializeBinary(output); // ������������ ����� �������� ������ � �������� ����
    output.write(reinterpret_cast<const char*>(&bedWidth), sizeof(bedWidth));
}

void Dump::deserializeBinary(std::ifstream& input) {
    Cargo::deserializeBinary(input); // �������������� ����� �������� ������ �� ��������� �����
    if (!input.read(reinterpret_cast<char*>(&bedWidth), sizeof(bedWidth))) {
        throw Exception_Vvod("������ ��� ������ ������ Dump �� ��������� �����.");
    }
}

// ���������� ��������� �����
std::istream& operator>>(std::istream& input, Dump& dumpObj) {
    try {
        input >> static_cast<Cargo&>(dumpObj); // ���� ������ �������� ������ Cargo
    }
    catch (const Exception& e) {
        throw; // ������������� ����������
    }

    do {
        std::cout << "������� ������ ������ (� ������): ";
        if (input >> dumpObj.bedWidth && dumpObj.bedWidth > 0) {
            break;
        }
        std::cerr << "������������ ������ ������. ��������� ����." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    return input;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& output, const Dump& dumpObj) {
    output << static_cast<const Cargo&>(dumpObj); // ����� �������� ������
    output << std::setw(15) << dumpObj.getBedWidth();
    return output;
}

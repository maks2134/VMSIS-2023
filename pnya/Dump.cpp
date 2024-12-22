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

// ���������� ��������� ������
std::istream& operator>>(std::istream& input, Dump& dumpObj) {
    try {
        input >> static_cast<Cargo&>(dumpObj); // ���� ������ �������� ������ Cargo
    }
    catch (const Exception& e) {
        throw; // ������������� ����������
    }

    std::cout << "������� ������ ������ (� ������): ";
    if (!(input >> dumpObj.bedWidth) || dumpObj.bedWidth <= 0) {
        throw Exception_Vvod("������������ ������ ������.");
    }

    return input;
}


// ���������� ��������� ������
std::ostream& operator<<(std::ostream& output, const Dump& dumpObj) {
    output << static_cast<const Cargo&>(dumpObj); // ����� �������� ������
    output << std::setw(15) << dumpObj.bedWidth;
    return output;
}
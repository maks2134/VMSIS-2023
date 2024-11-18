#include "Dump.h"

#include "Dump.h"
#include <iostream>

// ����������� �� ���������
Dump::Dump() : Cargo(), bedLength(0.0), bedWidth(0.0) {}

// ������������������� �����������
Dump::Dump(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles, double bedLength, double bedWidth)
    : Cargo(company, modal, year, loadCapacity, numberOfAxles), bedLength(bedLength), bedWidth(bedWidth) {}

// �������
double Dump::getBedLength() const {
    return bedLength;
}

double Dump::getBedWidth() const {
    return bedWidth;
}

// �������
void Dump::setBedLength(double bedLength) {
    this->bedLength = bedLength;
}

void Dump::setBedWidth(double bedWidth) {
    this->bedWidth = bedWidth;
}

// ���������� ��������� �����
std::istream& operator>>(std::istream& input, Dump& dumpObj) {
    input >> static_cast<Cargo&>(dumpObj); // ������ ��������� �������� ������
    std::cout << "������� ����� ������ (� ������): ";
    input >> dumpObj.bedLength;
    std::cout << "������� ������ ������ (� ������): ";
    input >> dumpObj.bedWidth;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Dump& dumpObj) {
    output << static_cast<const Cargo&>(dumpObj); // ����� ��������� �������� ������
    output << ", ����� ������: " << dumpObj.bedLength << " �, ������ ������: " << dumpObj.bedWidth << " �";
    return output;
}
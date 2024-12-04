#include "troll.h"
#include <iomanip>

// ����������� �� ���������
Troll::Troll() : Passanger(), electricPower(0) {}

// ����������������� �����������
Troll::Troll(const std::string& company, const std::string& modal, int year, int seatsNumber, const std::string& bodyType, int electricPower)
    : Passanger(company, modal, year, seatsNumber, bodyType), electricPower(electricPower) {
}
// ������ ��� electricPower
int Troll::getElectricPower() const {
    return electricPower;
}
// ������ ��� electricPower
void Troll::setElectricPower(int electricPower) {
    this->electricPower = electricPower;
}
// ������������� �������� �����
std::istream& operator >> (std::istream& input, Troll& trollObj) {
    input >> static_cast<Passanger&>(trollObj);
    std::cout << "������� �������-��������: ";
    input >> trollObj.electricPower;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Troll& trollObj) {
    output << static_cast<const Passanger&>(trollObj); // ����� �������� ������
    output << std::setw(15) << trollObj.electricPower;
    return output;
}

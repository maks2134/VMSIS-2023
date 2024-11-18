#include "Troll.h"

#include "troll.h"

// ����������� �� ���������
Troll::Troll() : Passanger(), electricPower(0) {}

// ����������������� �����������
Troll::Troll(const std::string& company, const std::string& modal, int year, int seatsNumber, const std::string& bodyType, int electricPower)
    : Passanger(company, modal, year, seatsNumber, bodyType), electricPower(electricPower) {}
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
    std::string company, modal, bodyType;
    int year, seatsNumber, electricPower;

    std::cout << "������� �������� ��������: ";
    input >> company;
    std::cout << "������� ������: ";
    input >> modal;
    std::cout << "������� ���: ";
    input >> year;
    std::cout << "������� ���������� ����: ";
    input >> seatsNumber;
    std::cout << "������� ��� ������: ";
    input >> bodyType;
    std::cout << "������� ������������� �������� (���): ";
    input >> electricPower;
    trollObj.setCompany(company);
    trollObj.setModal(modal);
    trollObj.setYear(year);
    trollObj.setSeatsNumber(seatsNumber);
    trollObj.setBodyType(bodyType);
    trollObj.setElectricPower(electricPower);

    return input;
}

// ������������� �������� ������
std::ostream& operator<<(std::ostream& output, const Troll& trollObj) {
    output << "��������: " << trollObj.getCompany() << "\n"
        << "������: " << trollObj.getModal() << "\n"
        << "���: " << trollObj.getYear() << "\n"
        << "���������� ����: " << trollObj.getSeatsNumber() << "\n"
        << "��� ������: " << trollObj.getBodyType() << "\n"
        << "������������� ��������: " << trollObj.getElectricPower() << " ���\n";

    return output;
}
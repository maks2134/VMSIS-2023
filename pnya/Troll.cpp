#include "troll.h"
#include <iomanip>
#include "Exception_Vvod.h"

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

void Troll::serialize(std::ofstream& output) const {
	Passanger::serialize(output); // ������������ ����� �������� ������
	output << ' ' << electricPower;
}

void Troll::deserialize(std::ifstream& input) {
	Passanger::deserialize(input); // �������������� ����� �������� ������
	if (!(input >> electricPower)) {
		throw Exception_Vvod("������ ��� ������ ������ Troll.");
	}
}

std::istream& operator>>(std::istream& input, Troll& trollObj) {
    try {
        input >> static_cast<Passanger&>(trollObj); // ���� ������ �������� ������ Passanger
    }
    catch (const Exception& e) {
        throw; // ������������� ����������
    }

    std::cout << "������� �������-��������: ";
    if (!(input >> trollObj.electricPower) || trollObj.electricPower <= 0) {
        throw Exception_Vvod("������������ �������� �������-��������.");
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Troll& trollObj) {
    output << static_cast<const Passanger&>(trollObj); // ����� �������� ������
    output << std::setw(15) << trollObj.electricPower;
    return output;
}
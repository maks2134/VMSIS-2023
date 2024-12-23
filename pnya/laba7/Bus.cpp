#include "Bus.h"
#include <iomanip>
#include "Exception_Vvod.h"

// ����������� �� ���������
Bus::Bus() : Passanger(), marKM(0) {}

// ����������������� �����������
Bus::Bus(const std::string& company, const std::string& modal, int year, int seatsNumber, std::string bodyType, int marKM)
    : Passanger(company, modal, year, seatsNumber, bodyType), marKM(marKM) {
}

// ������ ��� marKM
int Bus::getMarchuteKm() const {
    return marKM;
}

// ������ ��� marKM
void Bus::setMarchuteKm(int marKM) {
    this->marKM = marKM;
}

void Bus::serialize(std::ofstream& output) const {
    Passanger::serialize(output); // ������������ ����� �������� ������
    output << ' ' << marKM;
}

void Bus::deserialize(std::ifstream& input) {
    Passanger::deserialize(input); // �������������� ����� �������� ������
    if (!(input >> marKM)) {
        throw Exception_Vvod("������ ��� ������ ������ Bus.");
    }
}

std::istream& operator>>(std::istream& input, Bus& busObj) {
    try {
        input >> static_cast<Passanger&>(busObj); // ���� ������ �������� ������ Passanger
    }
    catch (const Exception& e) {
        throw; // ������������� ����������
    }

    std::cout << "������� ���������� ���������: ";
    if (!(input >> busObj.marKM) || busObj.marKM <= 0) {
        throw Exception_Vvod("������������ �������� ���������� ����������.");
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Bus& busObj) {
    output << static_cast<const Passanger&>(busObj); // ����� �������� ������
    output << std::setw(15) << busObj.marKM;
    return output;
}
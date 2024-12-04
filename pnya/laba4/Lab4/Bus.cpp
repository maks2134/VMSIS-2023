#include "Bus.h"
#include <iomanip>

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

// ������������� �������� �����
std::istream& operator>>(std::istream& input, Bus& busObj) {
    input >> static_cast<Passanger&>(busObj);
    std::cout << "������� ���������� ��: ";
    input >> busObj.marKM;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Bus& busObj) {
    output << static_cast<const Passanger&>(busObj); // ����� �������� ������
    output << std::setw(15) << busObj.marKM;
    return output;
}

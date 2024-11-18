#include "Bus.h"

// ����������� �� ���������
Bus::Bus() : Passanger(), marKM(0) {}

// ����������������� �����������
Bus::Bus(const std::string& company, const std::string& modal, int year, int seatsNumber, std::string bodyType, int marKM)
    : Passanger(company, modal, year, seatsNumber, bodyType), marKM(marKM) {}

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
    std::string company, modal, bodyType;
    int year, seatsNumber, marKM;

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
    std::cout << "������� ���������� ��: ";
    input >> marKM;

    busObj.setCompany(company);
    busObj.setModal(modal);
    busObj.setYear(year);
    busObj.setSeatsNumber(seatsNumber);
    busObj.setBodyType(bodyType);
    busObj.setMarchuteKm(marKM);

    return input;
}

// ������������� �������� ������
std::ostream& operator<<(std::ostream& output, const Bus& busObj) {
    output << "��������: " << busObj.getCompany() << "\n"
        << "������: " << busObj.getModal() << "\n"
        << "���: " << busObj.getYear() << "\n"
        << "���������� ����: " << busObj.getSeatsNumber() << "\n"
        << "��� ������: " << busObj.getBodyType() << "\n"
        << "���������� ��: " << busObj.getMarchuteKm() << "\n";

    return output;
}
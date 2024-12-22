#include "Auto.h"
#include <iomanip>
#include <sstream> // Include for stringstream
#include "Exception_Vvod.h"
#include <fstream>


Auto::Auto() : company(""), modal(""), year(0) {}

Auto::Auto(const std::string& company, const std::string& modal, int year)
    : company(company), modal(modal), year(year) {
}

Auto::Auto(const Auto& other)
    : company(other.company), modal(other.modal), year(other.year) {
}

std::string Auto::getCompany() const {
    return company;
}

std::string Auto::getModal() const {
    return modal;
}

int Auto::getYear() const {
    return year;
}

void Auto::setCompany(const std::string& company) {
    this->company = company;
}

void Auto::setModal(const std::string& modal) {
    this->modal = modal;
}

void Auto::setYear(int year) {
    this->year = year;
}

void Auto::serialize(std::ofstream& output) const {
    output << company << ' ' << modal << ' ' << year;
}

void Auto::deserialize(std::ifstream& input) {
    if (!(input >> company >> modal >> year)) {
        if (input.eof()) {
            throw Exception_Vvod("������ ��� ������ ������ Auto: ��������� ����� �����.");
        }
        else if (input.fail()) {
            throw Exception_Vvod("������ ��� ������ ������ Auto: �������� ������ ������.");
        }
        else {
            throw Exception_Vvod("������ ��� ������ ������ Auto: ����������� ������.");
        }
    }
}



std::ostream& operator<<(std::ostream& output, const Auto& autoObj) {
    output << std::left << std::setw(15) << autoObj.company
        << std::setw(15) << autoObj.modal
        << std::setw(10) << autoObj.year;
    return output;
}

std::istream& operator>>(std::istream& input, Auto& autoObj) {
	std::cout << "������� �������� ��������: ";
	if (!(input >> autoObj.company) || autoObj.company.empty()) {
		throw Exception_Vvod("������������ �������� ��������.");
	}

	std::cout << "������� ������: ";
	if (!(input >> autoObj.modal) || autoObj.modal.empty()) {
		throw Exception_Vvod("������������ ������.");
	}

	std::cout << "������� ��� �������: ";
	if (!(input >> autoObj.year) || autoObj.year < 1886 || autoObj.year > 2024) {
		throw Exception_Vvod("������������ ��� �������.");
	}

	return input;
}
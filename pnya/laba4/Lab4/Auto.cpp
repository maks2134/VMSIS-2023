#include "Auto.h"
#include <iomanip>

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

std::istream& operator>>(std::istream& input, Auto& autoObj) {
    std::cout << "¬ведите компанию авто: ";
    input >> autoObj.company;
    std::cout << "¬ведите модель авто: ";
    input >> autoObj.modal;
    std::cout << "¬ведите год авто: ";
    input >> autoObj.year;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Auto& autoObj) {
    output << std::left << std::setw(15) << autoObj.company
        << std::setw(15) << autoObj.modal
        << std::setw(10) << autoObj.year;
    return output;
}

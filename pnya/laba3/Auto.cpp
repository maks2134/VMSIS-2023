#include "Auto.h"

Auto::Auto() : company(""), modal(""), year(0) {}

Auto::Auto(const std::string &company, const std::string &modal, int year)
        : company(company), modal(modal), year(year) {}

Auto::Auto(const Auto &other)
        : company(other.company), modal(other.modal), year(other.year) {}

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

void Auto::setModal(const std::string &modal) {
    this->modal = modal;
}

void Auto::setYear(int year) {
    this->year = year;
}

std::istream& operator>>(std::istream &input, Auto &autoObj) {
    std::cout << "Введите компанию авто: ";
    input >> autoObj.company;
    std::cout << "Введите модель авто: ";
    input >> autoObj.modal;
    std::cout << "Введите год авто: ";
    input >> autoObj.year;
    return input;
}

std::ostream& operator<<(std::ostream &output, const Auto &autoObj) {
    output << "Компания: " << autoObj.company << ", Модель: " << autoObj.modal << ", Год: " << autoObj.year;
    return output;
}
#include "Auto.h"
#include <iomanip>
#include "Exception_Vvod.h"

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
    std::cout << "Введите компанию авто: ";
    if (!(input >> autoObj.company) || autoObj.company.empty()) {
        throw Exception_Vvod("Некорректное название компании.");
    }

    std::cout << "Введите модель авто: ";
    if (!(input >> autoObj.modal) || autoObj.modal.empty()) {
        throw Exception_Vvod("Некорректное название модели.");
    }

    std::cout << "Введите год авто: ";
    if (!(input >> autoObj.year) || autoObj.year < 1886 || autoObj.year > 2024) {
        throw Exception_Vvod("Некорректный год выпуска автомобиля.");
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Auto& autoObj) {
    output << std::left << std::setw(15) << autoObj.company
        << std::setw(15) << autoObj.modal
        << std::setw(10) << autoObj.year;
    return output;
}

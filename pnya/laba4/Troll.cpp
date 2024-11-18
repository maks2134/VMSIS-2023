#include "Troll.h"

#include "troll.h"

// Конструктор по умолчанию
Troll::Troll() : Passanger(), electricPower(0) {}

// Параметризованный конструктор
Troll::Troll(const std::string& company, const std::string& modal, int year, int seatsNumber, const std::string& bodyType, int electricPower)
    : Passanger(company, modal, year, seatsNumber, bodyType), electricPower(electricPower) {}
// Геттер для electricPower
int Troll::getElectricPower() const {
    return electricPower;
}
// Сеттер для electricPower
void Troll::setElectricPower(int electricPower) {
    this->electricPower = electricPower;
}
// Перегруженный оператор ввода
std::istream& operator >> (std::istream& input, Troll& trollObj) {
    std::string company, modal, bodyType;
    int year, seatsNumber, electricPower;

    std::cout << "Введите название компании: ";
    input >> company;
    std::cout << "Введите модель: ";
    input >> modal;
    std::cout << "Введите год: ";
    input >> year;
    std::cout << "Введите количество мест: ";
    input >> seatsNumber;
    std::cout << "Введите тип кузова: ";
    input >> bodyType;
    std::cout << "Введите электрическую мощность (кВт): ";
    input >> electricPower;
    trollObj.setCompany(company);
    trollObj.setModal(modal);
    trollObj.setYear(year);
    trollObj.setSeatsNumber(seatsNumber);
    trollObj.setBodyType(bodyType);
    trollObj.setElectricPower(electricPower);

    return input;
}

// Перегруженный оператор вывода
std::ostream& operator<<(std::ostream& output, const Troll& trollObj) {
    output << "Компания: " << trollObj.getCompany() << "\n"
        << "Модель: " << trollObj.getModal() << "\n"
        << "Год: " << trollObj.getYear() << "\n"
        << "Количество мест: " << trollObj.getSeatsNumber() << "\n"
        << "Тип кузова: " << trollObj.getBodyType() << "\n"
        << "Электрическая мощность: " << trollObj.getElectricPower() << " кВт\n";

    return output;
}
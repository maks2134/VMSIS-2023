#include "Bus.h"

// Конструктор по умолчанию
Bus::Bus() : Passanger(), marKM(0) {}

// Параметризованный конструктор
Bus::Bus(const std::string& company, const std::string& modal, int year, int seatsNumber, std::string bodyType, int marKM)
    : Passanger(company, modal, year, seatsNumber, bodyType), marKM(marKM) {}

// Геттер для marKM
int Bus::getMarchuteKm() const {
    return marKM;
}

// Сеттер для marKM
void Bus::setMarchuteKm(int marKM) {
    this->marKM = marKM;
}

// Перегруженный оператор ввода
std::istream& operator>>(std::istream& input, Bus& busObj) {
    std::string company, modal, bodyType;
    int year, seatsNumber, marKM;

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
    std::cout << "Введите маршрутные КМ: ";
    input >> marKM;

    busObj.setCompany(company);
    busObj.setModal(modal);
    busObj.setYear(year);
    busObj.setSeatsNumber(seatsNumber);
    busObj.setBodyType(bodyType);
    busObj.setMarchuteKm(marKM);

    return input;
}

// Перегруженный оператор вывода
std::ostream& operator<<(std::ostream& output, const Bus& busObj) {
    output << "Компания: " << busObj.getCompany() << "\n"
        << "Модель: " << busObj.getModal() << "\n"
        << "Год: " << busObj.getYear() << "\n"
        << "Количество мест: " << busObj.getSeatsNumber() << "\n"
        << "Тип кузова: " << busObj.getBodyType() << "\n"
        << "Маршрутные КМ: " << busObj.getMarchuteKm() << "\n";

    return output;
}
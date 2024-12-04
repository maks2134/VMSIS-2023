#include "Bus.h"
#include <iomanip>

// Конструктор по умолчанию
Bus::Bus() : Passanger(), marKM(0) {}

// Параметризованный конструктор
Bus::Bus(const std::string& company, const std::string& modal, int year, int seatsNumber, std::string bodyType, int marKM)
    : Passanger(company, modal, year, seatsNumber, bodyType), marKM(marKM) {
}

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
    input >> static_cast<Passanger&>(busObj);
    std::cout << "Введите маршрутные КМ: ";
    input >> busObj.marKM;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Bus& busObj) {
    output << static_cast<const Passanger&>(busObj); // Вывод базового класса
    output << std::setw(15) << busObj.marKM;
    return output;
}

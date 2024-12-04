#include "Bus.h"
#include <iomanip>
#include "Exception_Vvod.h"

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


std::istream& operator>>(std::istream& input, Bus& busObj) {
    try {
        input >> static_cast<Passanger&>(busObj); // Ввод данных базового класса Passanger
    }
    catch (const Exception& e) {
        throw; // Перебрасываем исключение
    }

    std::cout << "Введите маршрутные километры: ";
    if (!(input >> busObj.marKM) || busObj.marKM <= 0) {
        throw Exception_Vvod("Некорректное значение маршрутных километров.");
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Bus& busObj) {
    output << static_cast<const Passanger&>(busObj); // Вывод базового класса
    output << std::setw(15) << busObj.marKM;
    return output;
}
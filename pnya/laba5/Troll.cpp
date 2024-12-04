#include "troll.h"
#include <iomanip>
#include "Exception_Vvod.h"

// Конструктор по умолчанию
Troll::Troll() : Passanger(), electricPower(0) {}

// Параметризованный конструктор
Troll::Troll(const std::string& company, const std::string& modal, int year, int seatsNumber, const std::string& bodyType, int electricPower)
    : Passanger(company, modal, year, seatsNumber, bodyType), electricPower(electricPower) {
}
// Геттер для electricPower
int Troll::getElectricPower() const {
    return electricPower;
}
// Сеттер для electricPower
void Troll::setElectricPower(int electricPower) {
    this->electricPower = electricPower;
}

std::istream& operator>>(std::istream& input, Troll& trollObj) {
    try {
        input >> static_cast<Passanger&>(trollObj); // Ввод данных базового класса Passanger
    }
    catch (const Exception& e) {
        throw; // Перебрасываем исключение
    }

    std::cout << "Введите электро-мощность: ";
    if (!(input >> trollObj.electricPower) || trollObj.electricPower <= 0) {
        throw Exception_Vvod("Некорректное значение электро-мощности.");
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Troll& trollObj) {
    output << static_cast<const Passanger&>(trollObj); // Вывод базового класса
    output << std::setw(15) << trollObj.electricPower;
    return output;
}
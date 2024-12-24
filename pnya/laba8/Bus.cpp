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

void Bus::serialize(std::ofstream& output) const {
    Passanger::serialize(output); // Сериализация полей базового класса
    output << ' ' << marKM;
}

void Bus::deserialize(std::ifstream& input) {
    Passanger::deserialize(input); // Десериализация полей базового класса
    if (!(input >> marKM)) {
        throw Exception_Vvod("Ошибка при чтении данных Bus.");
    }
}

std::istream& operator>>(std::istream& input, Bus& busObj) {
    try {
        input >> static_cast<Passanger&>(busObj); // Ввод данных базового класса Passanger
    }
    catch (const Exception& e) {
        throw; // Перебрасываем исключение
    }

    do {
        std::cout << "Введите маршрутные километры: ";
        if (input >> busObj.marKM && busObj.marKM > 0) {
            break;
        }
        std::cerr << "Некорректное значение маршрутных километров. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    return input;
}


void Bus::serializeBinary(std::ofstream& output) const {
	Passanger::serializeBinary(output); // Сериализация полей базового класса
	output.write(reinterpret_cast<const char*>(&marKM), sizeof(marKM));
}

void Bus::deserializeBinary(std::ifstream& input) {
	Passanger::deserializeBinary(input); // Десериализация полей базового класса
	if (!input.read(reinterpret_cast<char*>(&marKM), sizeof(marKM))) {
		throw Exception_Vvod("Ошибка при чтении данных Bus.");
	}
}

std::ostream& operator<<(std::ostream& output, const Bus& busObj) {
    output << static_cast<const Passanger&>(busObj); // Вывод базового класса
    output << std::setw(15) << busObj.marKM;
    return output;
}
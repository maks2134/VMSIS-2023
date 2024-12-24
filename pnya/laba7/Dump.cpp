// В файл реализации Dump.cpp добавим определения методов для работы с бинарными файлами
#include "Dump.h"
#include <iomanip>
#include <fstream>
#include "Exception_Vvod.h"

// Конструктор по умолчанию
Dump::Dump() : Cargo(), bedWidth(0.0) {}

// Параметризированный конструктор
Dump::Dump(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles, double bedWidth)
    : Cargo(company, modal, year, loadCapacity, numberOfAxles), bedWidth(bedWidth) {
}

double Dump::getBedWidth() const {
    return bedWidth;
}

void Dump::setBedWidth(double bedWidth) {
    this->bedWidth = bedWidth;
}

void Dump::serialize(std::ofstream& output) const {
    Cargo::serialize(output); // Сериализация полей базового класса
    output << ' ' << bedWidth;
}

void Dump::deserialize(std::ifstream& input) {
    Cargo::deserialize(input); // Десериализация полей базового класса
    if (!(input >> bedWidth)) {
        throw Exception_Vvod("Ошибка при чтении данных Dump.");
    }
}

void Dump::serializeBinary(std::ofstream& output) const {
    Cargo::serializeBinary(output); // Сериализация полей базового класса в бинарный файл
    output.write(reinterpret_cast<const char*>(&bedWidth), sizeof(bedWidth));
}

void Dump::deserializeBinary(std::ifstream& input) {
    Cargo::deserializeBinary(input); // Десериализация полей базового класса из бинарного файла
    if (!input.read(reinterpret_cast<char*>(&bedWidth), sizeof(bedWidth))) {
        throw Exception_Vvod("Ошибка при чтении данных Dump из бинарного файла.");
    }
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& input, Dump& dumpObj) {
    try {
        input >> static_cast<Cargo&>(dumpObj); // Ввод данных базового класса Cargo
    }
    catch (const Exception& e) {
        throw; // Перебрасываем исключение
    }

    do {
        std::cout << "Введите ширину кузова (в метрах): ";
        if (input >> dumpObj.bedWidth && dumpObj.bedWidth > 0) {
            break;
        }
        std::cerr << "Некорректная ширина кузова. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    return input;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& output, const Dump& dumpObj) {
    output << static_cast<const Cargo&>(dumpObj); // Вывод базового класса
    output << std::setw(15) << dumpObj.getBedWidth();
    return output;
}

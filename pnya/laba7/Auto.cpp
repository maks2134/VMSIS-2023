#include "Auto.h"
#include <iomanip>
#include <sstream>
#include "Exception_Vvod.h"
#include <fstream>

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

void Auto::serialize(std::ofstream& output) const {
    output << company << ' ' << modal << ' ' << year;
}

void Auto::deserialize(std::ifstream& input) {
    if (!(input >> company >> modal >> year)) {
        if (input.eof()) {
            throw Exception_Vvod("Ошибка при чтении данных Auto: достигнут конец файла.");
        }
        else if (input.fail()) {
            throw Exception_Vvod("Ошибка при чтении данных Auto: неверный формат данных.");
        }
        else {
            throw Exception_Vvod("Ошибка при чтении данных Auto: неизвестная ошибка.");
        }
    }
}

void Auto::deserializeBinary(std::ifstream& input) {
    std::getline(input, company, '\0');
    std::getline(input, modal, '\0');
    input.read(reinterpret_cast<char*>(&year), sizeof(year));
}

void Auto::serializeBinary(std::ofstream& output) const {
	output.write(company.c_str(), company.size() + 1); // Запись строки с завершающим нулем
	output.write(modal.c_str(), modal.size() + 1); // Запись строки с завершающим нулем
	output.write(reinterpret_cast<const char*>(&year), sizeof(year));
}

std::ostream& operator<<(std::ostream& output, const Auto& autoObj) {
    output << std::left << std::setw(15) << autoObj.company
        << std::setw(15) << autoObj.modal
        << std::setw(10) << autoObj.year;
    return output;
}

std::istream& operator>>(std::istream& input, Auto& autoObj) {
    do {
        std::cout << "Введите название компании: ";
        if (input >> autoObj.company && !autoObj.company.empty()) {
            break;
        }
        std::cerr << "Некорректное название компании. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    do {
        std::cout << "Введите модель: ";
        if (input >> autoObj.modal && !autoObj.modal.empty()) {
            break;
        }
        std::cerr << "Некорректная модель. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    do {
        std::cout << "Введите год выпуска: ";
        if (input >> autoObj.year && autoObj.year >= 1886 && autoObj.year <= 2024) {
            break;
        }
        std::cerr << "Некорректный год выпуска. Повторите ввод." << std::endl;
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    return input;
}

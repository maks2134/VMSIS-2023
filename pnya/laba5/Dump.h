#ifndef LAB3_DUMP_H
#define LAB3_DUMP_H
#include "Cargo.h"

class Dump : public Cargo {
private:
    double bedWidth;  // Ширина кузова в метрах

public:
    // Конструктор по умолчанию
    Dump();
    // Параметризированный конструктор
    Dump(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles, double bedWidth);

    double getBedWidth() const;

    void setBedWidth(double bedWidth);

    // Перегрузка операторов ввода и вывода
    friend std::istream& operator>>(std::istream& input, Dump& dumpObj);
    friend std::ostream& operator<<(std::ostream& output, const Dump& dumpObj);
};

#endif //LAB3_DUMP_H
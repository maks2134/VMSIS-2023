#ifndef LAB3_DUMP_H
#define LAB3_DUMP_H
#include "Cargo.h"

class Dump : public Cargo {
private:
    double bedWidth;  // ������ ������ � ������

public:
    // ����������� �� ���������
    Dump();
    // ������������������� �����������
    Dump(const std::string& company, const std::string& modal, int year, double loadCapacity, int numberOfAxles, double bedWidth);

    double getBedWidth() const;

    void setBedWidth(double bedWidth);

    // ���������� ���������� ����� � ������
    friend std::istream& operator>>(std::istream& input, Dump& dumpObj);
    friend std::ostream& operator<<(std::ostream& output, const Dump& dumpObj);
};

#endif //LAB3_DUMP_H
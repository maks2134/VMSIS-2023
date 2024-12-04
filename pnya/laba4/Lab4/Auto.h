#ifndef LAB3_AUTO_H
#define LAB3_AUTO_H
#include <string>
#include <iostream>
#include <iomanip>

class Auto {
private:
    std::string company;
    std::string modal;
    int year;

public:
    Auto();
    Auto(const std::string& company, const std::string& modal, int year);

    Auto(const Auto& other);

    std::string getModal() const;
    void setModal(const std::string& modal);

    std::string getCompany() const;
    void setCompany(const std::string& company);

    int getYear() const;
    void setYear(int year);

    friend std::istream& operator>>(std::istream& input, Auto& autoObj);

    friend std::ostream& operator<<(std::ostream& output, const Auto& autoObj);
};

#endif
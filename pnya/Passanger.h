#ifndef LAB3_PASSANGER_H
#define LAB3_PASSANGER_H
#include "Auto.h"

class Passanger : public Auto {
private:
    int seatsNumber;
    std::string bodyType;

public:
    Passanger();
    Passanger(const std::string& company, const std::string& modal, int year, int seatsNumber, const std::string& bodyType);

    int getSeatsNumber() const;
    std::string getBodyType() const;

    void setSeatsNumber(int seatsNumber);
    void setBodyType(std::string bodyType);

	void serialize(std::ofstream& output) const;
	void deserialize(std::ifstream& input);

    friend std::istream& operator>>(std::istream& input, Passanger& passangerObj);
    friend std::ostream& operator<<(std::ostream& output, const Passanger& passangerObj);
};

#endif
#ifndef LAB3_TROLL_H
#define LAB3_TROLL_H
#include "passanger.h"
#include <fstream>

class Troll : public Passanger {
private:
    int electricPower;

public:
    Troll();
    Troll(const std::string& company, const std::string& modal, int year, int seatsNumber, const std::string& bodyType, int electricPower);

    int getElectricPower() const;
    void setElectricPower(int electricPower);

	void serialize(std::ofstream& output) const;
	void deserialize(std::ifstream& input);

    void serializeBinary(std::ofstream& output) const;
	void deserializeBinary(std::ifstream& input);

    friend std::istream& operator>>(std::istream& input, Troll& trollObj);
    friend std::ostream& operator<<(std::ostream& output, const Troll& trollObj);
};

#endif //LAB3_TROLL_H
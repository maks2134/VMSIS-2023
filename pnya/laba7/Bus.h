#ifndef LAB3_BUS_H
#define LAB3_BUS_H
#include "passanger.h"
#include <fstream>

class Bus : public Passanger {
private:
    int marKM;

public:
    Bus();
    Bus(const std::string& company, const std::string& modal, int year, int seatsNumber, std::string bodyType, int marKM);

    int getMarchuteKm() const;

    void setMarchuteKm(int marKM);

	void serialize(std::ofstream& output) const;
	void deserialize(std::ifstream& input);
    
    friend std::istream& operator>>(std::istream& input, Bus& pasObj);
    friend std::ostream& operator<<(std::ostream& output, const Bus& pasObj);
};


#endif
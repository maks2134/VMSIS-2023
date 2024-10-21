#ifndef LAB3_BUS_H
#define LAB3_BUS_H
#include "passanger.h"

class Bus: public Passanger {
private:
    int marKM;

public:
    Bus();
    Bus(const std::string &company, const std::string &modal, int year, int seatsNumber, std::string bodyType, int marKM);

    int getMarchuteKm() const;

    void setMarchuteKm(int marKM);

    friend std::istream& operator>>(std::istream &input, Bus &dumpObj);
    friend std::ostream& operator<<(std::ostream &output, const Bus &dumpObj);
};


#endif


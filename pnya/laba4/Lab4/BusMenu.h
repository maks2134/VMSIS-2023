#ifndef BUS_MENU_H
#define BUS_MENU_H

#include "Bus.h"
#include "Contant.h"
#include <iostream>
#include <iomanip>

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

class BusMenu {
public:
    BusMenu();
    void showMenu();

private:
    Stack<Bus> buses;

    void addBus();
    void displayBuses() const;
    void removeBus();
};

#endif

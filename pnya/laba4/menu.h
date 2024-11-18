#ifndef MENU_H
#define MENU_H

#include "Contant.h"
#include "Dump.h"
#include "Bus.h"
#include "Troll.h"

#include <iostream>
#include <string>

class Menu {
public:
    Menu();
    void showMenu();

private:
    Stack<Dump> dumpStack;
    Stack<Bus> busStack;
    Stack<Troll> trollStack;

    void addDump();
    void addBus();
    void addTroll();

    void displayDumps() const;
    void displayBuses() const;
    void displayTrolls() const;
    void printSeparator(const std::string& sep, int columns, int width) const;

    void removeDump();
    void removeBus();
    void removeTroll();
};

#endif
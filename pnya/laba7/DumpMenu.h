#ifndef DUMP_MENU_H
#define DUMP_MENU_H

#include "Dump.h"
#include "Contant.h"
#include "Algorithms.h"
#include <iostream>
#include <iomanip>

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

class DumpMenu {
public:
    DumpMenu();
    void showMenu();

private:
    Stack<Dump> dumps;

    void addDump();
    void displayDumps() const;
    void removeDump();
    void saveDumpsToFile();
    void loadDumpsFromFile();
    void sortDumps();
    void removeByCondition();
    void filterDumps() const;
};

#endif

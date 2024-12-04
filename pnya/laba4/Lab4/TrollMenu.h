#ifndef TROLL_MENU_H
#define TROLL_MENU_H

#include "Troll.h"
#include "Contant.h"
#include <iostream>
#include <iomanip>

#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

class TrollMenu {
public:
    TrollMenu();
    void showMenu();

private:
    Stack<Troll> trolls;

    void addTroll();
    void displayTrolls() const;
    void removeTroll();
};

#endif

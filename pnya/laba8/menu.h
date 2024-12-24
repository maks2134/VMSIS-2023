#ifndef MENU_H
#define MENU_H

#include "DumpMenu.h"
#include "BusMenu.h"
#include "TrollMenu.h"

class Menu {
public:
    Menu();
    void showMenu();

private:
    //DumpMenu dumpMenu;
    //BusMenu busMenu;
    TrollMenu trollMenu;
};

#endif

#ifndef TROLL_FILE_H
#define TROLL_FILE_H

#include "Troll.h"
#include <map>
#include <fstream>

class TrollFile {
public:
    TrollFile(const std::string& filename);
    void saveToFile(const std::multimap<int, Troll>& trolls) const;
    void loadFromFile(std::multimap<int, Troll>& trolls) const;

private:
    std::string filename;
};

#endif

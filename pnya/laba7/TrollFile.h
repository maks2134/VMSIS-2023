#ifndef TROLLFILE_H
#define TROLLFILE_H

#include "File.h"
#include "troll.h"

class TrollFile : public File<Troll> {
public:
    // Конструктор с передачей имени файла
    explicit TrollFile(const std::string& filename) : File(filename) {}
};

#endif // TROLLFILE_H

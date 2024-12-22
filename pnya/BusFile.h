#ifndef BUSFILE_H
#define BUSFILE_H

#include "File.h"
#include "Bus.h"

class BusFile : public File<Bus> {
public:
    // ����������� � ��������� ����� �����
    explicit BusFile(const std::string& filename) : File(filename) {}
};

#endif // BUSFILE_H

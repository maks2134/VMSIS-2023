#ifndef DUMPFILE_H
#define DUMPFILE_H

#include "File.h"
#include "Dump.h"

class DumpFile : public File<Dump> {
public:
    // ����������� � ��������� ����� �����
    explicit DumpFile(const std::string& filename) : File(filename) {}
};

#endif // DUMPFILE_H

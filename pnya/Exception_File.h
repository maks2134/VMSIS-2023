#ifndef EXCEPTION_FILE_H
#define EXCEPTION_FILE_H

#include "Exception.h"

// ���������� ��� ������ ������ � �������
class Exception_File : public Exception {
public:
    explicit Exception_File(const std::string& msg);
};

#endif // EXCEPTION_FILE_H
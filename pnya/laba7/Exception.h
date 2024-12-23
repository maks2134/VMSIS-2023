#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

// ������� ����� ����������
class Exception : public std::exception {
protected:
    std::string message;

public:
    explicit Exception(const std::string& msg);
    const char* what() const noexcept override;
};

#endif // EXCEPTION_H
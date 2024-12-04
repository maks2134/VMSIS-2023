#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

// Базовый класс исключений
class Exception : public std::exception {
protected:
    std::string message;

public:
    explicit Exception(const std::string& msg);
    const char* what() const noexcept override;
};

#endif // EXCEPTION_H
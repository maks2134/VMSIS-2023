#ifndef EXCEPTION_VVOD_H
#define EXCEPTION_VVOD_H

#include "Exception.h"

// Исключение для ошибок ввода
class Exception_Vvod : public Exception {
public:
    explicit Exception_Vvod(const std::string& msg);
};

#endif // EXCEPTION_VVOD_H
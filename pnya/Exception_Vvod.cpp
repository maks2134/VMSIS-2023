#include "Exception_Vvod.h"

Exception_Vvod::Exception_Vvod(const std::string& msg) : Exception("Ошибка ввода: " + msg) {}
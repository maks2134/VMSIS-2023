#include "Array.h"

// ����������� �� ���������
Array::Array() : intData(nullptr), strData(nullptr), size(0), isStringArray(false) {}

// ����������� � �����������
Array::Array(size_t size, bool isStringArray) : size(size), isStringArray(isStringArray) {
    if (isStringArray) {
        strData = new std::string[size](); // ������������� ������� �����
        intData = nullptr;
    }
    else {
        intData = new int[size](); // ������������� ������� ����� �����
        strData = nullptr;
    }
}

// ����������� �����������
Array::Array(const Array& other) : size(other.size), isStringArray(other.isStringArray) {
    if (isStringArray) {
        strData = new std::string[size];
        for (size_t i = 0; i < size; ++i) {
            strData[i] = other.strData[i]; // ����������� ����������� ������� �����
        }
        intData = nullptr;
    }
    else {
        intData = new int[size];
        for (size_t i = 0; i < size; ++i) {
            intData[i] = other.intData[i]; // ����������� ����������� ������� ����� �����
        }
        strData = nullptr;
    }
}

// ����������
Array::~Array() {
    delete[] intData; // ������������ ������ ��� ������� ����� �����
    delete[] strData; // ������������ ������ ��� ������� �����
}

// �������� ������������
Array& Array::operator=(const Array& other) {
    if (this == &other) {
        return *this; // �������� �� ����������������
    }

    delete[] intData; // ������������ ������
    delete[] strData;

    size = other.size; // ������� �������
    isStringArray = other.isStringArray; // ������� ���� �������

    if (isStringArray) {
        strData = new std::string[size];
        for (size_t i = 0; i < size; ++i) {
            strData[i] = other.strData[i]; // ����������� �����������
        }
        intData = nullptr;
    }
    else {
        intData = new int[size];
        for (size_t i = 0; i < size; ++i) {
            intData[i] = other.intData[i]; // ����������� �����������
        }
        strData = nullptr;
    }

    return *this; // ������� �������� �������
}

// �������� ��������
Array Array::operator+(const Array& other) const {
    if (size != other.size || isStringArray != other.isStringArray) {
        return Array(); // ������� ������� �������, ���� ������� ��� ���� �� ���������
    }

    Array result(size, isStringArray); // �������� ��������������� �������
    if (isStringArray) {
        for (size_t i = 0; i < size; ++i) {
            result.strData[i] = strData[i] + other.strData[i]; // �������� �����
        }
    }
    else {
        for (size_t i = 0; i < size; ++i) {
            result.intData[i] = intData[i] + other.intData[i]; // �������� ����� �����
        }
    }

    return result; // ������� ��������������� �������
}

// �������� ���������
Array Array::operator-(const Array& other) const {
    if (size != other.size || isStringArray != other.isStringArray) {
        return Array(); // ������� ������� �������, ���� ������� ��� ���� �� ���������
    }

    Array result(size, isStringArray); // �������� ��������������� �������
    if (!isStringArray) {
        for (size_t i = 0; i < size; ++i) {
            result.intData[i] = intData[i] - other.intData[i]; // ��������� ����� �����
        }
    }
    else {
        return Array(); // ������� ������� �������, ��� ��� ��������� ����� �� ��������������
    }

    return result; // ������� ��������������� �������
}

// �������� �������� �� �������
Array Array::operator+(const std::string& str) const {
    if (!isStringArray) {
        return Array(); // ������� ������� �������, ���� ������ �� ���������
    }

    Array result(size, isStringArray); // �������� ��������������� �������
    for (size_t i = 0; i < size; ++i) {
        result.strData[i] = strData[i] + str; // �������� ������ � ������ ��������� �������
    }

    return result; // ������� ��������������� �������
}

// �������� ������
std::ostream& operator<<(std::ostream& os, const Array& array) {
    if (array.isStringArray) {
        for (size_t i = 0; i < array.size; ++i) {
            os << array.strData[i] << " "; // ����� �����
        }
    }
    else {
        for (size_t i = 0; i < array.size; ++i) {
            os << array.intData[i] << " "; // ����� ����� �����
        }
    }
    return os; // ������� ������
}

// �������� �����
std::istream& operator>>(std::istream& is, Array& array) {
    if (array.isStringArray) {
        for (size_t i = 0; i < array.size; ++i) {
            is >> array.strData[i]; // ���� �����
        }
    }
    else {
        for (size_t i = 0; i < array.size; ++i) {
            is >> array.intData[i]; // ���� ����� �����
        }
    }
    return is; // ������� ������
}

// ����� ��������� �������� ������ �����
void Array::set(size_t index, int value) {
    if (isStringArray || index >= size) {
        return; // ���� ������ ��������� ��� ������ ��� ���������, ������ �� ������
    }
    intData[index] = value; // ��������� ��������
}

// ����� ��������� �������� ������
void Array::set(size_t index, const std::string& value) {
    if (!isStringArray || index >= size) {
        return; // ���� ������ �� ��������� ��� ������ ��� ���������, ������ �� ������
    }
    strData[index] = value; // ��������� ��������
}

// ����� ��������� �������� ������ �����
int Array::getInt(size_t index) const {
    if (isStringArray || index >= size) {
        return 0; // ������� 0, ���� ������ ��������� ��� ������ ��� ���������
    }
    return intData[index]; // ������� ��������
}

// ����� ��������� �������� ������
std::string Array::getString(size_t index) const {
    if (!isStringArray || index >= size) {
        return ""; // ������� ������ ������, ���� ������ �� ��������� ��� ������ ��� ���������
    }
    return strData[index]; // ������� ��������
}

// ����� ��� ������ ����������� �������
void Array::print() const {
    if (isStringArray) {
        for (size_t i = 0; i < size; ++i) {
            std::cout << strData[i] << " "; // ����� �����
        }
    }
    else {
        for (size_t i = 0; i < size; ++i) {
            std::cout << intData[i] << " "; // ����� ����� �����
        }
    }
    std::cout << std::endl; // ������� ������
}
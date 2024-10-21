#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>

class Array {
private:
    int* intData;               // ��������� �� ������ ����� �����
    std::string* strData;       // ��������� �� ������ �����
    size_t size;                // ������ �������
    bool isStringArray;         // ����, �����������, �������� �� ������ ���������

public:
    Array();                    // ����������� �� ���������
    Array(size_t size, bool isStringArray = false); // ����������� � �����������
    Array(const Array& other);  // ����������� �����������
    ~Array();                   // ����������

    Array& operator=(const Array& other); // �������� ������������

    Array operator+(const Array& other) const; // �������� ��������
    Array operator-(const Array& other) const; // �������� ���������
    Array operator+(const std::string& str) const; // �������� �������� �� �������

    friend std::ostream& operator<<(std::ostream& os, const Array& array); // �������� ������
    friend std::istream& operator>>(std::istream& is, Array& array); // �������� �����

    void set(size_t index, int value); // ����� ��������� �������� ��� ������ �����
    void set(size_t index, const std::string& value); // ����� ��������� �������� ��� ������
    int getInt(size_t index) const; // ����� ��������� �������� ������ �����
    std::string getString(size_t index) const; // ����� ��������� �������� ������

    void print() const; // ����� ��� ������ ����������� �������
};

#endif // ARRAY_H
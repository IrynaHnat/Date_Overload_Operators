#pragma once
#include <iostream>
#include <string>

using std::string;
using std::to_string;

class Date {
public:
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    
    int operator-(const Date& other) const;
    Date& operator+=(int days);

    void print() const;

private:
    int day;
    int month;
    int year;

    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;
    int toDays() const;  
    void fromDays(int totalDays);
    bool isValidDate(int day, int month, int year) const;
};

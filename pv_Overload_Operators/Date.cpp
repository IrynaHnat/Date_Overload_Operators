#include "Date.h"
#include <iostream>

using std::cout;
using std::endl;


Date::Date(int day, int month, int year) {
    if (isValidDate(day, month, year)) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else {
        cout << "Invalid date. Setting default date (1/1/1)." << endl;
        this->day = 1;
        this->month = 1;
        this->year = 1;
    }
}

bool Date::isValidDate(int day, int month, int year) const {
    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        return false;
    }
    return true;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year) const {
    const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) return 29;
    return daysPerMonth[month - 1];
}

int Date::toDays() const {
    int totalDays = day;
    for (int y = 1; y < year; ++y) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; ++m) {
        totalDays += daysInMonth(m, year);
    }
    return totalDays;
}

void Date::fromDays(int totalDays) {
    year = 1;
    while (totalDays > (isLeapYear(year) ? 366 : 365)) {
        totalDays -= isLeapYear(year) ? 366 : 365;
        ++year;
    }
    month = 1;
    while (totalDays > daysInMonth(month, year)) {
        totalDays -= daysInMonth(month, year);
        ++month;
    }
    day = totalDays;
}

int Date::operator-(const Date& other) const {
    int days1 = this->toDays();
    int days2 = other.toDays();
    return days1 > days2 ? days1 - days2 : days2 - days1;
}

Date& Date::operator+=(int days) {
    int totalDays = this->toDays() + days;
    fromDays(totalDays);
    return *this;
}

void Date::print() const {
    cout << day << "/" << month << "/" << year <<endl;
}

#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date date1(11, 10, 2023);
    Date date2(22, 10, 2024);

    date1.print();
    date2.print();

    int daysDifference = date2 - date1;
    cout << "Difference in days: " << daysDifference <<endl;

    date1 += 15;
    cout << "Date after adding 15 days: " << endl;;
    date1.print();
}

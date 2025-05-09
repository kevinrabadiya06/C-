#include <iostream>
#include <iomanip>

using namespace std;


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getNumDaysInMonth(int month, int year) {
    switch (month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}


void displayCalendar(int month, int year) {
    cout << "  S  M Tu  W Th  F  S" << endl;
    int numDays = getNumDaysInMonth(month, year);
    int startDay = 1;
    switch (month) {
        case 1:
            if (year > 1753) startDay = (startDay + (year - 1753) + (year - 1753) / 4 - (year - 1753) / 100 + (year - 1753) / 400) % 7;
            break;
        default:
            break;
    }


    for (int i = 0; i < startDay; i++) {
        cout << "   ";
    }


    for (int day = 1; day <= numDays; day++) {
        cout << setw(2) << day << " ";
        if ((startDay + day) % 7 == 0)
            cout << endl;
    }
}

int main() {
    int month, year;
    char k;

    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;


    cout << "\n\n";
    displayCalendar(month, year);
    cout << endl;
    return 0;
}







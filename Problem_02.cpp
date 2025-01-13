#include <iostream>
using namespace std;

string IsLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0) {
            return "Leap Year";
        } else {
            if (year % 400 == 0) {
                return "Leap Year";
            } else {
                return "Not Leap Year";
            }
        }
    } else {
        return "Not Leap Year";
    }
}

int ReadNumber() {
    int year = 0;
    while (true) {
        cout << "Please enter a number: ";
        cin >> year;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid number.\n";
        } else {
            break; // Exit the loop if input is valid
        }
    }
    return year;
}

int main() {
    cout << IsLeapYear(ReadNumber()) << endl;
    return 0;
}
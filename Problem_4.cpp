#include <iostream>
using namespace std;
bool IsLeapYear(short Year)
{
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}

short NumberOfDayInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year)
{
    return Year * 24;
}

int NumberOfMinutesInYear(short Year)
{
    return Year * 24 * 60;
}

int  NumberOfSecondsInYear(short Year)
{
    return Year * 24 * 60*60;
}


void Timeinformation(short Year)
{
    short NumberDay = NumberOfDayInYear(Year);
    cout << "Number of Days in Year ["<< Year << "] is " << NumberDay << endl;
    cout << "Number of Hours in Year [" << Year << "] is " << NumberOfHoursInYear(NumberDay) << endl;
    cout << "Number of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(NumberDay) << endl;
    cout << "Number of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(NumberDay) << endl;

}

int main()
{

    short Year = ReadYear();
    Timeinformation(Year);

    return 0;
}
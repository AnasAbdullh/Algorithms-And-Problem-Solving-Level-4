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

short ReadMonths()
{
    short Months;

    cout << "\nPlease enter a Month to check? ";
    cin >> Months;
    return Months;
}

short NumberOfDaysInMonths(short Year,short Months)
{
    return (Months < 0 || Months > 12) ? 0 : (Months == 2) ? (IsLeapYear(Year) ? 29 : 28) : (Months == 1 || 3 ||5||7||8||10||12) ? 31 : 30;
}

short NumberOfHoursInMonths(short Year,short Months)
{
    return NumberOfDaysInMonths(Year,Months) * 24;  // تم تصحيح الاسم هنا
}

int NumberOfMinutesInMonths(short Year,short Months)
{
    return NumberOfHoursInMonths(Year,Months) * 60;
}

int NumberOfSecondsInMonths(short Year,short Months)
{
    return NumberOfMinutesInMonths(Year,Months) * 60;
}

void Timeinformation()
{
    short Year = ReadYear();
    short Months = ReadMonths();

    cout << "\nNumber of Days in    [" << Months << "] is " << NumberOfDaysInMonths(Year,Months);
    cout << "\nNumber of Hours in   [" << Months << "] is "  << NumberOfHoursInMonths(Year,Months);
    cout << "\nNumber of Minutes in [" << Months << "] is "  << NumberOfMinutesInMonths(Year,Months);
    cout << "\nNumber of Seconds in [" << Months << "] is " << NumberOfSecondsInMonths(Year,Months);
}

int main()
{
    Timeinformation();

    return 0;
}
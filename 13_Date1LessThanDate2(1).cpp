#include <iostream>
using namespace std;
struct stDate
{
    short Year;
    short Month;
    short Day;
};

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    if(Date1.Year < Date2.Year)
        return true;

    if(Date1.Year > Date2.Year)
        return false;

    if(Date1.Month < Date2.Month)
        return true;

    if(Date1.Month > Date2.Month)
        return false;

    return (Date1.Day < Date2.Day);
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}
stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
short ReadDaysToAdd()
{
    short Days;
    cout << "\nHow many days to add? ";
    cin >> Days;
    return Days;
}
int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (IsDate1EqualDate2(Date1,Date2))
        cout << "Yes, Date1 is Less than Date2.";
    else
        cout << "Not, Date1 is Less than Date2.";

    return 0;
}
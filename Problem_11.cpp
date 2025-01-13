#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInAMonth(int Month, int Year)
{
    if (Month < 1 || Month>12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :  days[Month - 1];
}

int ValdidNumber(short Number,short & day,short Year )
{
    short count = 1;

    for (int i = 1; i <= 12; i++)
    {
        Number -=NumberOfDaysInAMonth(i,Year);
        count++;
        if(Number == day) {
            day = Number;
            break;
        }
    }

    return count ;
}

int CountNumberDay(int Year,int Day, short Month)
{
    int count = 0;
    for (int i = 1; i <= Month -1; i++)
    {
        count += NumberOfDaysInAMonth(i,Year);
    }
    count += Day;
    return count;
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
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}
int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    short countNumber = CountNumberDay(Year,Day,Month);
    short valid = ValdidNumber(countNumber,Day,Year);

    cout << Day << "/" << valid << "/" << Year << endl;


    return 0;
}
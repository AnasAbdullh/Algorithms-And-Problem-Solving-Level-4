#include <iostream>
using namespace std;

struct InfoDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;

};

InfoDate ReadDate()
{
    InfoDate Date;

    cout << "Please enter a year ? :" ;
    cin >> Date.Year;

    cout << "Please enter a Month ? :";
    cin >> Date.Month;

    cout << "Please enter a Day ? :";
    cin >> Date.Day;

    return Date;
}

short DayOrder(short Day)
{
    return Day / 7;
}

string DayName(short Day)
{
    string daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return daysOfWeek[Day / 7];
}

void PeintDate(InfoDate Date)
{
    cout << "Date       :" << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    cout << "Day Order  :" << DayOrder(Date.Day) << endl;
    cout << "Day Name   :" << DayName(Date.Day) << endl;
}
int main()
{

    PeintDate(ReadDate());
    return 0;
}

#include <iostream>
using namespace std;
struct stDate
{
    short Year;
    short Month;
    short Day;
};
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month,Date.Year));
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)  / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {
        "Sun","Mon","Tue","Wed","Thu","Fri","Sat"
    };
    return arrDayNames[DayOfWeekOrder];
}

stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}


short DayOfWeekOrder(stDate Date)
{
    short DayOrder = DayOfWeekOrder(Date.Day,Date.Month,Date.Year);

    return DayOrder ;
}

bool IsEndWeek(string endweek)
{
    if (endweek == "Sat") {

        return true ;
    }
    return false;
}

bool IsWeekEnd(string weekend )
{
    if ( weekend == "Fri") {

        return true ;
    }
    return false;

}

bool IsBusinessDay(string BusinessDay)
{
    if ( BusinessDay == "Fri" || BusinessDay == "Sat" ) {

        return false ;
    }
    return true;

}

short DaysUntilTheEndOfWeek(short End)
{
    return (6 - End);
}

void CountNumberDayOfWeeks(stDate & Date,short & count)
{

    string Name = DayShortName(Date.Day);
    while (true) {
        Name = DayShortName(Date.Day);
        if ( Name != "Sat") {
            count ++;
            Date.Day++;
        } else {

            break;
        }
    }
}


int DaysUntilTheEndOfMonth(stDate Date)
{
    short count = 0;
    short NumberOfDays =  NumberOfDaysInAMonth(Date.Month, Date.Year);

    while(true) {

        if(Date.Day != NumberOfDays) {

            count++;
            Date.Day++;
        } else {
            count++;
            Date.Day = 1;
            break;
        }

    }

    CountNumberDayOfWeeks(Date,count);

    return count - 1;

}

int DaysUntilTheEndOfYear(stDate Date) {

    short count = 0;
    short NumberOfDays =  NumberOfDaysInAMonth(Date.Month, Date.Year);

    while(true) {

        if(Date.Year != 12) {

            if(Date.Day != NumberOfDays) {

                count++;
                Date.Day++;
            } else {
                count++;
                Date.Day = 1;
                break;
            }
        } else {

            Date.Year++;
            break;
        }
    }
    
    CountNumberDayOfWeeks(Date,count);

    return count - 1;
    

}

void PrintDateAndToday(stDate Date)
{

    cout << "Today is " << DayShortName(DayOfWeekOrder(Date))  <<" ," << Date.Day <<"/" << Date.Month << "/" << Date.Year << endl;

}

int main()
{

    stDate Date = GetSystemDate();

    string DayName = DayShortName(DayOfWeekOrder(Date));

    PrintDateAndToday(Date);
    cout << "Is it End of Week?" << endl;
    if(IsEndWeek(DayName)) {

        cout << "yes this end of week" << endl;
    } else {

        cout << "No Not end of week" << endl;
    }
    cout << "Is it Weekend ?" << endl;
    if(IsWeekEnd(DayName)) {

        cout << "Yes it is a week end" << endl;
    } else {

        cout << "Not it is a week end" << endl;
    }

    if(IsBusinessDay(DayName)) {

        cout << "Yes it is a business day." << endl;
    } else {

        cout << "No it is NOT a business day." << endl;
    }

    cout << DaysUntilTheEndOfWeek(DayOfWeekOrder(Date)) << endl;
    cout << DaysUntilTheEndOfMonth(Date) << endl;
    cout << DaysUntilTheEndOfYear(Date) << endl;

    return 0;
}
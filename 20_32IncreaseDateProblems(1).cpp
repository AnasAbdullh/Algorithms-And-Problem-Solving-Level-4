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
    if (Month < 1 || Month>12) {
        return 0;
    }
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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}


stDate IncreaseDateByOneDay(stDate & Date)
{
    if (IsLastDayInMonth(Date)) {

        if (IsLastMonthInYear(Date.Month)) {

            Date.Month = 1;
            Date.Year++;
            Date.Day = 1;
        } else {
            Date.Day = 1;
            Date.Month = Date.Month + 1;
        }

    } else {
        Date.Day ++;
    }

    return Date;
}

stDate IncreaseDateByXDays(short Days, stDate & Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByOneWeek(short week,stDate & Date)
{

    for (short i = 1; i <= week ; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXWeeks(short weeks,stDate & Date)
{

    for (short i = 1; i <= weeks ; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;

}

stDate IncreaseDateByOneMonth(stDate & Date)
{
    if(Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;

    } else {

        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month,Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth )
    {

        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return  Date;
}

stDate IncreaseDateByXMonths(short Month,stDate & Date)
{
    for (short i = 1; i <= Month ; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;

}


stDate IncreaseDateByOneYear(stDate & Date)
{
    ++Date.Year;
    return Date;
}

stDate IncreaseDateByXYears(short Year,stDate & Date)
{
    for (short i = 1; i <= Year; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;

}

stDate IncreaseDateByXYearsFaster(short Year,stDate & Date)
{
    Date.Year += Year;

}

stDate IncreaseDateByOneDecade(stDate & Date)
{

    Date.Year += 10;
    return Date;
}

stDate IncreaseDateByXDecades(short Decades stDate & Date)
{
    for (short i = 1; i <= Decades * 10 ; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    
    return Date;
}

void IncreaseDateByXDecadesFaster(stDate & Date)
{

    Date.Year = Date.Year * 10;
}

void IncreaseDateByOneCentury(stDate & Date )
{

    Date.Year += 100;
}

void IncreaseDateByOneMillennium(stDate & Date)
{
    Date.Year += 1000;

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
    Date.Day = 31;
    Date.Month = 2;
    Date.Year = 2022;
    return Date;
}

int main()
{
    //stDate Date1 = ReadFullDate();
    stDate Date = ReadFullDate();

    Date = IncreaseDateByOneDay(Date);
    cout << "Date after adding one day is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByXDays(Date);
    cout << "Date after adding 10 day is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByOneWeek(Date);
    cout << "Date after adding One week is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByXWeeks(Date);
    cout << "Date after adding 10 week is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByOneMonth(Date);
    cout << "Date after adding One Month is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByXMonths(Date);
    cout << "Date after adding 5 Month is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByOneYear(Date);
    cout << "Date after adding One Year is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByXYears(Date);
    cout << "Date after adding 10 Year is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByXYearsFaster(Date);
    cout << "Date after adding 10 Year (faster) is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByOneDecade(Date);
    cout << "Date after adding one Decade is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByXDecades(Date);
    cout << "Date after adding 10 Decade is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByXDecadesFaster(Date);
    cout << "Date after adding 10 Decade (faster) is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByOneCentury(Date);
    cout << "Date after adding one Century is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    IncreaseDateByOneMillennium(Date);
    cout << "Date after adding One Millennium is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";





    return 0;
}

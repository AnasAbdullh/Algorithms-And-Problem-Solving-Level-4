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

stDate DateAddDays(short Days, stDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

stDate IncreaseDateByOneDay(stDate Date)
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

void IncreaseDateByXDays(stDate & Date)
{

    Date = IncreaseDateByOneDay(Date);
    Date.Day = Date.Day + 9;

}

void IncreaseDateByOneWeek(stDate & Date)
{


    Date = IncreaseDateByOneDay(Date);
    Date.Day = Date.Day + 6;
}

void IncreaseDateByXWeeks(stDate & Date)
{

    Date =DateAddDays(70,Date);

}

void IncreaseDateByOneMonth(stDate & Date)
{

    Date = DateAddDays(NumberOfDaysInAMonth(Date.Month,Date.Year),Date);

}

void IncreaseDateByXMonths(stDate & Date)
{
    Date = DateAddDays(NumberOfDaysFromTheBeginingOfTheYear(Date.Day,5,Date.Year),Date);
    Date.Day = Date.Day + 4;

}


void IncreaseDateByOneYear(stDate & Date)
{
    ++Date.Year;
}

void IncreaseDateByXYears(stDate & Date)
{
    Date.Year = Date.Year + 10;

}

void IncreaseDateByXYearsFaster(stDate & Date)
{
    Date.Year = Date.Year + 10;

}

void IncreaseDateByOneDecade(stDate & Date)
{

    Date.Year = Date.Year + 10;

}

void IncreaseDateByXDecades(stDate & Date)
{

    Date.Year = Date.Year + 100;

}

void IncreaseDateByXDecadesFaster(stDate & Date)
{

    Date.Year = Date.Year + 100;
}

void IncreaseDateByOneCentury(stDate & Date )
{

    Date.Year = Date.Year + 100;
}

void IncreaseDateByOneMillennium(stDate & Date)
{
    Date.Year = Date.Year + 1000;

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

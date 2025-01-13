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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
        return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
                               Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
                                                      Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}



void SwapDate(stDate & Date1, stDate & Date2)
{
    stDate Temp;
    Temp.Day = Date1.Day;
    Temp.Month = Date1.Month;
    Temp.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = Temp.Day;
    Date2.Month = Temp.Month;
    Date2.Year = Temp.Year;

}

stDate IncreaseDateByOneDay(stDate Date);

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short vailu = 1;

    if(!IsDate1BeforeDate2(Date1, Date2)) {
        SwapDate(Date1,Date2);
        vailu = -1;

    }

    while (IsDate1BeforeDate2(Date1, Date2)) {
            
         Days++;
         Date1 = IncreaseDateByOneDay(Date1);
            
    }

     return IncludeEndDay ? ++Days * vailu : Days *  vailu;
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
    return DayOfWeekOrder(Date.Day,Date.Month,Date.Year);

}

short IsEndWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    return  ( DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 5);
}

bool IsBusinessDay(stDate Date)
{
    return ! IsWeekEnd(Date);

}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return(6 - DayOfWeekOrder(Date));
}


int DaysUntilTheEndOfMonth(stDate Date)
{
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month ;
    EndOfMonthDate.Year = Date.Year ;

    return GetDifferenceInDays(Date,EndOfMonthDate,true);
}

int DaysUntilTheEndOfYear(stDate Date)
{

    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year ;

    return GetDifferenceInDays(Date,EndOfYearDate,true);

}

void PrintDateAndToday(stDate Date)
{

    cout << "Today is " << DayShortName(DayOfWeekOrder(Date))  <<" ," << Date.Day <<"/" << Date.Month << "/" << Date.Year << endl;

}

short CalculateVacationDays(stDate Date, short NumbersDay)
{
    short Vacation = 0;
    for(short i = 0 ; i < NumbersDay ; i++) {

        if(IsWeekEnd(Date)) {
            Vacation++;

        }
        Date = IncreaseDateByOneDay(Date);
    }

    return Vacation;

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

int main()
{
    cout << "Vacation Starts" << endl;
    stDate Date = ReadFullDate();

    cout << "\nVacation Ends" << endl;
    stDate Vacation = ReadFullDate();

    string NameDay = DayShortName(DayOfWeekOrder(Date));
    cout << "Vaction From : " <<  NameDay << "  " ;
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    NameDay = DayShortName(DayOfWeekOrder(Vacation));
    cout << "Vaction To   : " <<  NameDay << "  ";
    cout << Vacation.Day << "/" << Vacation.Month << "/" << Vacation.Year << endl;

    int NumbersDay = GetDifferenceInDays(Date,Vacation,true);
    
    cout << "Actucal Vacation Days is: " << CalculateVacationDays(Date,NumbersDay) << endl;








    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return 0;
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31  };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :  NumberOfDays[Month - 1];
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
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

string PrintNameMonths(short Months)
{
    string NameMonths[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    return NameMonths[Months -1];
}


void PrintCalendar(short Year, short Month)
{
    short crrucrt = DayOfWeekOrder(1,Month,Year);
    short NumberOfDays = NumberOfDaysInAMonth(Month,Year);
    cout << crrucrt << endl;
    cout << NumberOfDays  << endl;

    cout << string(15,'-') << PrintNameMonths(Month) << string(15,'-') << endl;
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i ;
    for(i = 0 ; i < crrucrt ; i++ )
        printf("     ");


  //  cout << i  << "Upper"<< endl;
    for(short j = 1 ; j <= NumberOfDays; j++ )
    {
        printf("%5d",j);
        
        if (i++ == 7) {

            i = 0;

            printf("\n");
        }
        //   cout << i << "Lower" << endl;
    }

}

int main()
{

    //  short Year = ReadYear();
    //  short Month = ReadMonth();

    PrintCalendar(2022,9);


    return 0;
}
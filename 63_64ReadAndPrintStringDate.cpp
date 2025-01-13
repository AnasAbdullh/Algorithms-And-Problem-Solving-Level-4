#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct stDate
{
    int Year;
    int Month;
    int Day;
};
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false): false;
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) ==
        enDateCompare::Before
        ||
        CompareDates(Period2.StartDate, Period1.EndDate) ==
        enDateCompare::After
    )
        return false;
    else
        return true;
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

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    short count = 0;

    if(IsOverlapPeriods(Period1,Period2))
    {
        while(IsDate1BeforeDate2(Period2.StartDate,Period1.EndDate))
        {
            count++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }

    }

    return count ;

}

bool IsValiDateDate(stDate Date)
{
    if (Date.Day < 1 || Date.Day > 31 ) {

        return false;
    }
    if (Date.Month < 1 || Date.Month > 12 ) {

        return false;
    }

    if (Date.Month == 2) {

        if(isLeapYear(Date.Year)) {

            if (Date.Day > 29) {
                return false ;

            }

        } else {

            if (Date.Day > 28) {
                return false;
            }
        }

    }

    short DayMonth = NumberOfDaysInAMonth(Date.Month,Date.Year);

    if (Date.Day > DayMonth ) {
        return false;

    }

    return true;
}

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
// use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);

        }
        S1.erase(0, pos + Delim.size()); /* erase() until
positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

stDate StringToDate(string Date)
{
    stDate structDate;
    vector <string> vStructDate = SplitString(Date,"/");

    structDate.Day =  stoi(vStructDate[0]);
    structDate.Month = stoi(vStructDate[1]);
    structDate.Year = stoi(vStructDate[2]);

    return structDate;

}

string DateToString(stDate Date)
{
    string text = to_string(Date.Day) + "/" + to_string(Date.Month) +"/"+ to_string(Date.Year);
    return text;

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
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "Please enter a Year? ";
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
stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

string ReadDate()
{
    string Date = "";
    cout << "Please Enter Date dd/mm/yyyy ?";
    cin >> Date;
    return Date;
}

int main()
{

    stDate Date = StringToDate(ReadDate());

    cout << Date.Day << endl;
    cout << Date.Month << endl;
    cout << Date.Year << endl;

    cout << "You Entered : " << DateToString(Date);


    return 0;
}

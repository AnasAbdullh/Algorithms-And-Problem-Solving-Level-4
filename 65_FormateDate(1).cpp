#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stDate
{
    short Year;
    short Month;
    short Day;
};
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
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

string ReplaceWords(string S1,string StringToReplace,string ReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != S1.npos) {

        S1 = S1.replace(pos,StringToReplace.length(), ReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}


string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
stDate StringToDate(string DateString)
{
    stDate Date;
    vector <string> vDate;
    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}
string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

string FormateDate(stDate Date , string ToReplace = "dd/mm/yyyy")
{
    string FormatDate = "";
    FormatDate = ReplaceWords(ToReplace,"dd",to_string(Date.Day));
    FormatDate = ReplaceWords(FormatDate,"mm",to_string(Date.Month));
    FormatDate = ReplaceWords(FormatDate,"yyyy",to_string(Date.Year));
    
    return FormatDate;

}

int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

    stDate Date = StringToDate(DateString);

    cout << FormateDate(Date) << endl;
    cout << FormateDate(Date,"mm/dd/yyyy") << endl;




    return 0;
}
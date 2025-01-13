#include <iostream>
using namespace std;

string NumberToText(int Number) {
    if (Number == 0) {
        return "Zero";
    }

    if (Number < 0) {
        return "Minus " + NumberToText(-Number);
    }

    if (Number >= 1 && Number <= 19) {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                        "Eighteen", "Nineteen"
                       };
        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99) {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + (Number % 10 != 0 ? " " + NumberToText(Number % 10) : "");
    }

    if (Number >= 100 && Number <= 999) {
        return NumberToText(Number / 100) + "Hundred" + (Number % 100 != 0 ? " and " + NumberToText(Number % 100) : "");
    }

    if (Number >= 1000 && Number <= 999999) {
        return NumberToText(Number / 1000) + "Thousand" + (Number % 1000 != 0 ? " " + NumberToText(Number % 1000) : "");
    }

    if (Number >= 1000000 && Number <= 999999999) {
        return NumberToText(Number / 1000000) + "Million" + (Number % 1000000 != 0 ? " " + NumberToText(Number % 1000000) : "");
    }

    if (Number >= 1000000000) {
        return NumberToText(Number / 1000000000) + "Billion" + (Number % 1000000000 != 0 ? " " + NumberToText(Number % 1000000000) : "");
    }

    return ""; // يجب أن لا يصل التنفيذ إلى هنا
}

int ReadNumber() {
    int Number = 0;
    cout << "Please enter a number: ";
    cin >> Number;
    return Number;
}

int main() {
    cout << NumberToText(ReadNumber()) << endl;
    return 0;
}
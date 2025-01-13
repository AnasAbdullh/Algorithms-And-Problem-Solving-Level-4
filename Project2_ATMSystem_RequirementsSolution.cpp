#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum enAtmMainMenue {
  enQuickWithdraw = 1,
  enNormalWithdraw = 2,
  enDeposit = 3,
  enCheckBalance = 4,
  enLogout = 5
};

const string ClientsFileName = "/storage/emulated/0/OutputFilesCpp/Client.txt";

void ShowMainMenue();

void Login();

struct sClient {
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  double AccountBalance;
  bool MarkForDelete = false;
};

sClient currentClient;

vector<string> SplitString(string S1, string Delim) {
  vector<string> vString;
  short pos = 0;
  string sWord;

  while ((pos = S1.find(Delim)) != std::string::npos) {
    sWord = S1.substr(0, pos);
    if (sWord != "") {
      vString.push_back(sWord);
    }
    S1.erase(0, pos + Delim.length());
  }

  if (S1 != "") {
    vString.push_back(S1);
  }

  return vString;
}



sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
  sClient Client;
  vector<string> vClientData;

  vClientData = SplitString(Line, Seperator);

  // Ignore lines that do not have exactly 5 fields
  if (vClientData.size() < 5) {
    std::cerr << "Error: Insufficient fields in line: " << Line << std::endl;
    return Client; // Return a default-constructed client
  }

  Client.AccountNumber = vClientData[0];
  Client.PinCode = vClientData[1];
  Client.Name = vClientData[2];
  Client.Phone = vClientData[3];

  // Validate and convert the balance field
  try {
    Client.AccountBalance = stod(vClientData[4]);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: Invalid balance value (" << vClientData[4]
              << ") in line: " << Line << std::endl;
    Client.AccountBalance = 0.0; // Set a default value in case of error
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: Balance value out of range (" << vClientData[4]
              << ") in line: " << Line << std::endl;
    Client.AccountBalance = 0.0; // Set a default value in case of error
  }

  return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
  string stClientRecord = "";

  stClientRecord += Client.AccountNumber + Seperator;
  stClientRecord += Client.PinCode + Seperator;
  stClientRecord += Client.Name + Seperator;
  stClientRecord += Client.Phone + Seperator;
  stClientRecord += to_string(Client.AccountBalance);

  return stClientRecord;
}


vector<sClient> LoadCleintsDataFromFile(string FileName) {

  vector<sClient> vClients;

  fstream MyFile;
  MyFile.open(FileName, ios::in); // read Mode

  if (MyFile.is_open()) {

    string Line;
    sClient Client;

    while (getline(MyFile, Line)) {

      Client = ConvertLinetoRecord(Line);

      vClients.push_back(Client);
    }

    MyFile.close();
  }

  return vClients;
}


bool FindNumberAccountAndPinCode(string AccountNumber, string PinCode, sClient &Client) {

  vector<sClient> vClent = LoadCleintsDataFromFile(ClientsFileName);

  for (const auto &U : vClent) {

    if (U.AccountNumber == AccountNumber && U.PinCode == PinCode) {
      Client = U;
      return true;
    }
  }
  return false;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {

  fstream MyFile;
  MyFile.open(FileName, ios::out); // overwrite

  string DataLine;

  if (MyFile.is_open()) {

    for (sClient C : vClients) {

      if (C.MarkForDelete == false) {
        // we only write records that are not marked for delete.
        DataLine = ConvertRecordToLine(C);
        MyFile << DataLine << endl;
      }
    }

    MyFile.close();
  }

  return vClients;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }


        return false;
    }
    
    return false;
}



void ShowATMmainMenue();

void GoBackToMainMenue() {
  cout << "\n\nPress any key to go back to Main Menue...";
  system("read");
  ShowATMmainMenue();
}

short ReadWithdrawChoose() {
  short Choose = 0;
  do {
    
    cout << "Choose what to withdraw from[1] to [8]?";
    cin >> Choose;
    
  } while (Choose < 0 || Choose > 8);
  
  return Choose;
}

void UpdateCurrent(sClient &Client) {
  vector<sClient> vClent = LoadCleintsDataFromFile(ClientsFileName);

  for (const auto &U : vClent) {

    if (U.AccountNumber == currentClient.AccountNumber &&
        U.PinCode == currentClient.PinCode) {
      Client = U;
    }
  }
}

int switchWithdraw(short choose) {

  switch (choose) {
  case 1: {

    return 20;
    break;
  }
  case 2: {

    return 50;
    break;
  }
  case 3: {
    return 100;
    break;
  }
  case 4: {
    return  200;
    break;
  }
  case 5: {

    return 400;
    break;
  }
  case 6: {
  return  600;
    break;
  }
  case 7: {

    return 800;
    break;
  }
  case 8: {

    return 1000;
    break;
  }
  default: {
     
     return 0;
     break;
   }
   
  }
  return 0;
}

void ScreenAmounTexceeds() {
  
  cout << "The amount exceeds your balance, make another choice." << endl;
  cout << "Press Anykey to continue..." << endl;
  system("read");
  ShowATMmainMenue();
}



void QuickWithdraw() {
  
  short choose = ReadWithdrawChoose();
  double Withdraw = switchWithdraw(choose);

  if (Withdraw > currentClient.AccountBalance) {

    ScreenAmounTexceeds();
    return;
  }
  
  vector<sClient> vClient = LoadCleintsDataFromFile(ClientsFileName);
  DepositBalanceToClientByAccountNumber(currentClient.AccountNumber, Withdraw * -1, vClient);
  currentClient.AccountBalance -= Withdraw;

}

void ShowQuickWithdrawScreen() {
  
  system("clear");
  cout << "===========================================\n";
  cout << "\t\tQuick Withdraw\n";
  cout << "===========================================\n";
  cout << "\t[1] 20  \t[2] 50" << endl;
  cout << "\t[3] 100 \t[4] 200" << endl;
  cout << "\t[5] 400 \t[6] 600" << endl;
  cout << "\t[7] 800 \t[8] 1000" << endl;
  cout << "\t[9] Exit " << endl;
  cout << "===========================================\n";
  cout << "Your Balance is :" << currentClient.AccountBalance << endl;
  QuickWithdraw();
}

short ReadAtmMainMenue() {
  short choose = 0;
  cout << "Choose what do you want to do? [1 to 5]?";
  cin >> choose;
  return choose;
}

double  ReadtNormalWithdraw() {
  short NormalWithdraw = 0;
  do {
    
    cout << "Enter an amount multiple of 5's ? ";
    cin >> NormalWithdraw;
    
  } while (NormalWithdraw % 5 != 0);
  
  return NormalWithdraw;
}

void showNormalWithdraw() {

  system("clear");
  cout << "===========================================\n";
  cout << "\t\tNormal Withdraw Screen\n";
  cout << "===========================================\n";
   
  double NormalWithdraw = ReadtNormalWithdraw();
  
  if (NormalWithdraw > currentClient.AccountBalance)
  {
    ScreenAmounTexceeds();
    return;
    
  }
  
  vector<sClient> vClient = LoadCleintsDataFromFile(ClientsFileName);
  DepositBalanceToClientByAccountNumber(currentClient.AccountNumber, NormalWithdraw * -1, vClient);
  currentClient.AccountBalance -= NormalWithdraw;

}

short ReadshowDepositScreen()
{
  short Deposit;
  
  do {
    
  cout << "Enter a positive Deposit Amount?";
  cin >> Deposit;
    
  } while (Deposit <= 0);
  
  return Deposit;
  
}

void AddDeposit()
{
  double Deposit = ReadshowDepositScreen();
  
  vector<sClient> vClient = LoadCleintsDataFromFile(ClientsFileName);
  DepositBalanceToClientByAccountNumber(currentClient.AccountNumber, Deposit, vClient);
  currentClient.AccountBalance += Deposit;
  
}


void showDepositScreen()
{
  
  system("clear");
  cout << "===========================================\n";
  cout << "\t\tDeposit Screen\n";
  cout << "===========================================\n";
  
  AddDeposit();
  
}

void CheckBalanceScreen()
{
  
  system("clear");
  cout << "===========================================\n";
  cout << "\t\tDeposit Screen\n";
  cout << "===========================================\n";
  cout << "Yor Balance is : " << currentClient.AccountBalance << endl;
  
}

void PerfromAtmMainMenue(enAtmMainMenue choose) {

  switch (choose) {
  case enAtmMainMenue::enQuickWithdraw: {
    system("clear");
    ShowQuickWithdrawScreen();
    GoBackToMainMenue();
    break;
  }
  case enAtmMainMenue::enNormalWithdraw:
    system("clear");
    showNormalWithdraw();
    GoBackToMainMenue();
    break;

  case enAtmMainMenue::enDeposit:
    system("clear");
    showDepositScreen();
    GoBackToMainMenue();
    break;

  case enAtmMainMenue::enCheckBalance:
    system("clear");
    CheckBalanceScreen();
    GoBackToMainMenue();
    break;

  case enAtmMainMenue::enLogout:
    system("clear");
    Login();
    break;

  }
}

void ShowATMmainMenue() {
  system("clear");
  cout << "===========================================\n";
  cout << "\t\tATM Main Menue Screen\n";
  cout << "===========================================\n";
  cout << "\t[1] Quick Withdraw.\n";
  cout << "\t[2] Normal Withdraw.\n";
  cout << "\t[3] Deposit.\n";
  cout << "\t[4] Check Balance .\n";
  cout << "\t[5] Logout.\n";
  cout << "===========================================\n";

  PerfromAtmMainMenue((enAtmMainMenue)ReadAtmMainMenue());
}

bool LoadClientInfo(string NumberAccount, string PinCode) {

  if (FindNumberAccountAndPinCode(NumberAccount, PinCode, currentClient))
    return true;
  else
    return false;
}

void Login() {
  bool LoginFaild = false;

  string NumberAccount, PinCode;
  do {
    system("clear");

    cout << "\n---------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n---------------------------------\n";

    if (LoginFaild) {
      cout << "Invlaid Account Number/PinCode!\n";
    }

    cout << "Enter Number Account ? ";
    cin >> NumberAccount;

    cout << "Enter PinCode ? ";
    cin >> PinCode;

    LoginFaild = !LoadClientInfo(NumberAccount, PinCode);

  } while (LoginFaild);

  ShowATMmainMenue();
}

int main()

{
  Login();

  system("read");
  return 0;
}

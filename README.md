# VeglaSoftuerike
Një depo për kodim kreativ, testimin e ideve të reja dhe ndërtimin e gjërave interesante në kod.
Hello world
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
//Struktura per ruajtjen e detajeve te llogarise bankare
struct Account {
    int accountNumber;
    string accountHolder;
    floatbalance;
    };
    // Klasa për Sistemin e Menaxhimit të Bankës
class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        Account newAccount;
        cout << "\nFut numrin e llogarisë: ";
        cin >> newAccount.accountNumber;
        cin.ignore();  // për të konsumuar karakterin 'newline' që mbetet nga cin
        cout << "Fut emrin e mbajtësit të llogarisë: ";
        getline(cin, newAccount.accountHolder);
        newAccount.balance = 0.0f;

        accounts.push_back(newAccount);
        cout << "Llogaria u krijua me sukses!\n";
    }
    

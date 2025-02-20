#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <regex>

using namespace std;

// Structure to store transaction details
struct Transaction {
    string type;
    double amount;
    string accountType;
    string timestamp;
};

// Bank Account Class
class BankAccount {
private:
    char accountHolderName[50];
    char accountNumber[15];
    char email[50];
    char password[20];
    double creditAccountBalance;
    double debitAccountBalance;
    vector<Transaction> transactionHistory;

    string getTimestamp();

public:
    BankAccount(const char* name, const char* accNumber, const char* userEmail, const char* userPassword);
    bool authenticate(const std::string& inputEmail, const std::string& inputPassword);
    void deposit(double amount, const string& accountType);
    void withdraw(double amount, const string& accountType);
    void displayAccountDetails();
    void viewTransactionHistory();
};

bool isValidPassword(const string& password);
bool isValidEmail(const string& email);
BankAccount createAccount();
bool login(BankAccount& account);
void mainMenu(BankAccount& account);

#endif // BANK_ACCOUNT_H

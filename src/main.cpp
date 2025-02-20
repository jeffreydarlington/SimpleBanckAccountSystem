#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <regex>  // For email validation
#include "BankAccount.h"
using namespace std;

// Main Function
int main() {
    BankAccount userAccount = createAccount();

    if (login(userAccount)) {
        mainMenu(userAccount);
    }

    return 0;
}

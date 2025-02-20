#include "BankAccount.h"
using namespace std;

string BankAccount::getTimestamp()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	dt[strlen(dt) - 1] = '\0';
	return string();
}

BankAccount::BankAccount(const char* name, const char* accNumber, const char* userEmail, const char* userPassword)
{
	strncpy(accountHolderName, name, 50);
	strncpy(accountNumber, accNumber, 15);
	strncpy(email, userEmail, 50);
	strncpy(password, userPassword, 20);
	creditAccountBalance = 0.0;
	debitAccountBalance = 0.0;
}

bool BankAccount::authenticate(const std::string& inputEmail, const std::string& inputPassword) {
    return (email == inputEmail) && (password == inputPassword);
}


void BankAccount::deposit(double amount, const string& accountType)
{
	if (amount <= 0) {
		cout << "Invalid deposit amount!" << endl;
		return;
	}

	if (accountType == "credit") {
		creditAccountBalance += amount;
	}
	else if(accountType == "debit") {
		debitAccountBalance += amount;
	}
	else {
		cout << "Invalid account type!" << endl;
		return;
	}

	transactionHistory.push_back({"Deposit", amount, accountType, getTimestamp()});

	cout << "Deposit successful";
}

void BankAccount::withdraw(double amount, const string& accountType)
{
    if (amount <= 0) {
        cout << "Invalid withdrawal amount!" << endl;
        return;
    }

    if (accountType == "credit" && creditAccountBalance >= amount) {
        creditAccountBalance -= amount;
    }
    else if (accountType == "debit" && debitAccountBalance >= amount) { // Fixed condition
        debitAccountBalance -= amount;
    }
    else {
        cout << "Insufficient funds!" << endl; // Fixed typo
        return;
    }

    transactionHistory.push_back({ "Withdrawal", amount, accountType, getTimestamp() });
    cout << "Withdrawal successful!\n";
}


void BankAccount::displayAccountDetails()
{
	cout << "\n=== Account Details ===\n";
	cout << "Account Holder: " << accountHolderName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Email: " << email << endl;
	cout << "Credit Account Balance: $" << fixed << setprecision(2) << creditAccountBalance << endl;
	cout << "Debit Account Balance: $" << fixed << setprecision(2) << debitAccountBalance << endl;
}

void BankAccount::viewTransactionHistory() {
	cout << "\n=== Transaction History ===\n";
	if (transactionHistory.empty()) {
		cout << "No transactions yet.\n";
		return;
	}

	for (const auto& transaction : transactionHistory) {
		cout << transaction.timestamp << " | " << transaction.type
			<< " | $" << fixed << setprecision(2) << transaction.amount
			<< " | " << transaction.accountType << endl;
	}
}

bool isValidPassword(const string& password)
{
	if (password.length() < 6) return false;

	bool hasNumber = false, hasSpecialChar = false;
	string specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";

	for (char c : password) {
		if (isdigit(c)) hasNumber = true;
		if (specialChars.find(c) != string::npos) hasSpecialChar = true;

		if (hasNumber && hasSpecialChar) return true; // If both conditions met
	}
	return false;
}

// Function to validate email
bool isValidEmail(const string& email) {
    // Ensure the email contains '@'
    if (email.find('@') == string::npos) {
        return false;
    }

    // Regex pattern for more detailed validation
    regex pattern(R"(^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return regex_match(email, pattern);
}

// Function to create a bank account
BankAccount createAccount() {
    char name[50], accountNum[15], email[50], password[20];

    // Validate name
    do {
        cout << "Enter your name (min 3 characters): ";
        cin.getline(name, 50);
    } while (strlen(name) < 3);

    // Validate account number
    do {
        cout << "Enter your account number (min 6 digits): ";
        cin.getline(accountNum, 15);
    } while (strlen(accountNum) < 6);

    // Validate email
    do {
        cout << "Enter your email: ";
        cin.getline(email, 50);
        if (!isValidEmail(email)) {
            cout << "Invalid email format! Try again.\n";
        }
    } while (!isValidEmail(email));

    // Validate password with numbers and symbols
    do {
        cout << "Enter your password (min 6 characters, must include a number & special character): ";
        cin.getline(password, 20);
        if (!isValidPassword(password)) {
            cout << "Invalid password! It must be at least 6 characters long and contain at least one number and one special character.\n";
        }
    } while (!isValidPassword(password));

    cout << "Account created successfully!\n";
    return BankAccount(name, accountNum, email, password);
}

// Function to handle user login
bool login(BankAccount& account) {
    char loginEmail[50], loginPassword[20];

    while (true) {
        cout << "\nLogin\nEnter email: ";
        cin.getline(loginEmail, 50);
        cout << "Enter password: ";
        cin.getline(loginPassword, 20);

        if (account.authenticate(loginEmail, loginPassword)) {
            cout << "Login successful!\n";
            return true;
        }
        else {
            cout << "Invalid credentials. Try again.\n";
        }
    }
}

// Main Menu
void mainMenu(BankAccount& account) {
    int choice;
    double amount;
    string accountType;

    do {
        cout << "\n1. View Account Details\n2. Deposit Money\n3. Withdraw Money\n4. Transaction History\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            account.displayAccountDetails();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter account type (credit/debit): ";
            getline(cin, accountType);
            account.deposit(amount, accountType);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter account type (credit/debit): ";
            getline(cin, accountType);
            account.withdraw(amount, accountType);
            break;
        case 4:
            account.viewTransactionHistory();
            break;
        case 5:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option! Try again.\n";
        }
    } while (choice != 5);
}

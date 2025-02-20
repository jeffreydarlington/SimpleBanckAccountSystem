# Bank Account Management System

## Overview
This is a simple C++ Bank Account Management System that allows users to create an account, log in, deposit and withdraw money, and view transaction history. The system supports both credit and debit accounts.

## Features
- **Account Creation**: Users can create a bank account by providing their name, account number, email, and password.
- **Authentication**: Secure login system with email and password validation.
- **Deposit Money**: Users can deposit funds into their credit or debit account.
- **Withdraw Money**: Users can withdraw funds, ensuring sufficient balance before processing.
- **View Account Details**: Displays the account holder's information and balances.
- **Transaction History**: Logs deposits and withdrawals with timestamps.

## Technologies Used
- **C++** for programming logic
- **Standard Template Library (STL)** for vectors (transaction storage)
- **Regex** for email validation
- **ctime** for timestamps
- **cstring** for string handling

## Files
- `BankAccount.h`: Header file containing the class definition and function prototypes.
- `BankAccount.cpp`: Implementation of the `BankAccount` class and its methods.
- `main.cpp`: The main program that handles user interactions.

## How to Compile and Run
1. Ensure you have a C++ compiler (e.g., g++).
2. Open a terminal or command prompt and navigate to the project directory.
3. Compile the program:
   ```sh
   g++ main.cpp BankAccount.cpp -o bank_app
   ```
4. Run the program:
   ```sh
   ./bank_app
   ```

## Usage Instructions
1. **Create an Account**: Enter your details following the prompts.
2. **Login**: Use your email and password to access the system.
3. **Perform Transactions**:
   - View account details.
   - Deposit funds (credit or debit account).
   - Withdraw funds (with balance verification).
   - View transaction history.
4. **Exit**: Choose the exit option to close the program.

## Future Enhancements
- Implement file/database storage for persistent account and transaction data.
- Improve security by hashing passwords.
- Enhance UI with a better menu system.
- Support for multiple users.

## Author
- **Jeffrey Darlington**

## License
This project is open-source and available for personal or educational use.


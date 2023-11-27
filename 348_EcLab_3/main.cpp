#include <iostream>
#include <string>

using namespace std;

// Base Account class
class Account {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accountNumber, string accountHolder, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolder = accountHolder;
        this->balance = balance;
    }

    void displayDetails() {
        cout << "Account Details for " << accountNumber << ":" << endl;
        cout << "   Holder: " << accountHolder << endl; 
        cout << "   Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }
};

// Savings Account class
class SavingsAccount : public Account {
private:
    double interestRate;
    double minBalance = 500;

public:
    SavingsAccount(string accountNumber, string accountHolder, double balance, double interestRate) 
        : Account(accountNumber, accountHolder, balance) {
        this->interestRate = interestRate;
    }

    void displayDetails() {
        Account::displayDetails();
        cout << "   Interest Rate: " << interestRate*100 << "%" << endl;
    }

    void withdraw(double amount) {
        if (balance - amount >= minBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw below minimum balance" << endl; 
        }
    }
};


// Current Account class 
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accountNumber, string accountHolder, double balance, double overdraftLimit)
        : Account(accountNumber, accountHolder, balance) {
        this->overdraftLimit = overdraftLimit;
    }

    void displayDetails() {
         Account::displayDetails();
         cout << "   Overdraft Limit: $" << overdraftLimit << endl;
    }

    void withdraw(double amount) {
        if (balance - amount >= -overdraftLimit) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot exceed overdraft limit" << endl;
        }
    }
};

// Operator overloading
void operator+(CurrentAccount &current, SavingsAccount &savings) {
    double transferAmount = 300;
    savings.withdraw(transferAmount);
    current.deposit(transferAmount);
}

ostream& operator<<(ostream &out, Account &acc) {
    acc.displayDetails();
    return out;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);
    
    cout << savings << current << endl;
    
    savings.deposit(500);
    current.withdraw(1000);
    
    cout << savings << current << endl;
    
    current + savings;
    
    cout << savings << current << endl;

    return 0;
}
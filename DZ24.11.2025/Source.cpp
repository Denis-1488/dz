#include <iostream>
#include <string>
using namespace std;

class NegativeAmountException {
    string msg;
public:
    NegativeAmountException(const string& m) : msg(m) {}
    string message() const { return msg; }
};

class NotEnoughFundsException {
    string msg;
public:
    NotEnoughFundsException(const string& m) : msg(m) {}
    string message() const { return msg; }
};

class BankAccount {
    string owner;
    double balance;
public:
    BankAccount(string o, double b) : owner(o), balance(b) {}

    void deposit(double amount) {
        if (amount <= 0) throw NegativeAmountException("Deposit must be > 0");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) throw NegativeAmountException("Withdraw must be > 0");
        if (amount > balance) throw NotEnoughFundsException("Not enough money");
        balance -= amount;
    }

    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc("Ivan", 500);

    try {
        acc.deposit(200);
        cout << "Balance after deposit: " << acc.getBalance() << endl;

        acc.withdraw(100);
        cout << "Balance after withdraw: " << acc.getBalance() << endl;

        acc.withdraw(1000); // Error
    }
    catch (NegativeAmountException& e) {
        cout << "Error: " << e.message() << endl;
    }
    catch (NotEnoughFundsException& e) {
        cout << "Error: " << e.message() << endl;
    }

    try {
        acc.deposit(-50); // Error
    }
    catch (NegativeAmountException& e) {
        cout << "Error: " << e.message() << endl;
    }
}

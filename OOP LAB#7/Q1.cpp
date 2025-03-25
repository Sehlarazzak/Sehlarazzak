#include <iostream>
#include <vector>

using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    Account(int accNum, double bal, string name) 
        : accountNumber(accNum), balance(bal), accountHolderName(name) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    virtual bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn " << amount << ". Remaining balance: " << balance << endl;
        return true;
    }

    virtual double calculateInterest() = 0;

    virtual void printStatement() const {
        cout << "Account Number: " << accountNumber << ", Holder: " << accountHolderName
             << ", Balance: " << balance << endl;
    }
    
    virtual ~Account() {} 
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, double bal, string name, double rate, double minBal)
        : Account(accNum, bal, name), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override {
        return balance * interestRate / 100;
    }

    bool withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Cannot withdraw. Minimum balance required: " << minimumBalance << endl;
            return false;
        }
        return Account::withdraw(amount);
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Savings Account with Interest Rate: " << interestRate << "%" << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityDate;  

public:
    FixedDepositAccount(int accNum, double bal, string name, double rate, int matDate)
        : Account(accNum, bal, name), fixedInterestRate(rate), maturityDate(matDate) {}

    double calculateInterest() override {
        return balance * fixedInterestRate / 100;
    }

    bool withdraw(double amount) override {
        cout << "Withdrawals are not allowed before maturity date!" << endl;
        return false;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Fixed Deposit Account with Interest Rate: " << fixedInterestRate 
             << "%, Maturity Date: " << maturityDate << endl;
    }
};

int main() {
    SavingsAccount sa(101, 5000, "Sehla", 3.5, 1000);
    FixedDepositAccount fda(102, 10000, "Anna", 5.0, 2027);

    sa.deposit(2000);
    sa.withdraw(4000);
    sa.printStatement();

    fda.printStatement();
    fda.withdraw(1000);  

    return 0;
}


#include <iostream>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into " << accountNumber << " | New Balance: " << balance << "\n";
    }
    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from " << accountNumber << " | New Balance: " << balance << "\n";
            return true;
        } else {
            cout << "Insufficient funds in " << accountNumber << "\n";
            return false;
        }
    }
    virtual void applyMonthlyProcess() = 0; 
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}
    void applyMonthlyProcess() override {
        balance += balance * (interestRate / 100);
        cout << "Interest applied to " << accountNumber << " | New Balance: " << balance << "\n";
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}
    bool withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from " << accountNumber << " | New Balance: " << balance << "\n";
            return true;
        } else {
            cout << "Overdraft limit exceeded for " << accountNumber << "\n";
            return false;
        }
    }
    void applyMonthlyProcess() override {}
};

class BusinessAccount : public BankAccount {
private:
    double taxRate;

public:
    BusinessAccount(string accNum, double bal, double tax) : BankAccount(accNum, bal), taxRate(tax) {}
    void deposit(double amount) override {
        double tax = amount * (taxRate / 100);
        balance += (amount - tax);
        cout << "Deposited " << amount << " into " << accountNumber << " (Tax deducted: " << tax << ") | New Balance: " << balance << "\n";
    }
    void applyMonthlyProcess() override {}
};

class User {
protected:
    string name;

public:
    User(string n) : name(n) {}
    virtual void performOperation(BankAccount &account, double amount) = 0;
    virtual ~User() {}
};

class Customer : public User {
public:
    Customer(string n) : User(n) {}
    void performOperation(BankAccount &account, double amount) override {
        account.deposit(amount);
    }
};

class Teller : public User {
public:
    Teller(string n) : User(n) {}
    void performOperation(BankAccount &account, double amount) override {
        account.withdraw(amount);
    }
};

class Manager : public User {
public:
    Manager(string n) : User(n) {}
    void performOperation(BankAccount &account, double amount) override {
        account.deposit(amount);
        account.withdraw(amount / 2); 
    }
};

int main() {
    SavingsAccount savings("SAV123", 1000, 5);
    CheckingAccount checking("CHK123", 500, 200);
    BusinessAccount business("BUS123", 2000, 10);
    Customer customer("Alice");
    Teller teller("Bob");
    Manager manager("Charlie");   
    cout << "\nCustomer performing deposit:\n";
    customer.performOperation(savings, 500);   
    cout << "\nTeller performing withdrawal:\n";
    teller.performOperation(checking, 600);   
    cout << "\nManager performing operations:\n";
    manager.performOperation(business, 1000);
    cout << "\nApplying monthly processes:\n";
    savings.applyMonthlyProcess();
    
    return 0;
}

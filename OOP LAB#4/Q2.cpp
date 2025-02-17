#include <iostream>

class Account {
private:
    double balance;

public:
    Account(double initialBalance) 
	{
        if (initialBalance >= 0) 
		{
            balance = initialBalance;
        } else {
            balance = 0;
            std::cerr << "Initial balance invalid. Setting balance to 0." << std::endl;
        }
    }

    void credit(double amount) 
	{
        if (amount > 0) 
		{
            balance += amount;
        } else {
            std::cerr << "Invalid credit amount." << std::endl;
        }
    }

    void debit(double amount) 
	{
        if (amount > 0 && amount <= balance) 
		{
            balance -= amount;
        } else {
            std::cerr << "Debit amount exceeded account balance or is invalid." << std::endl;
        }
    }

    double getBalance() const 
	{
        return balance;
    }
};

int main() {
    Account myAccount(1000.0);
    
    std::cout << "Initial Balance: " << myAccount.getBalance() << std::endl;
    
    myAccount.credit(500.0);
    std::cout << "Balance after credit: " << myAccount.getBalance() << std::endl;
    
    myAccount.debit(200.0);
    std::cout << "Balance after debit: " << myAccount.getBalance() << std::endl;
    
    return 0;
}


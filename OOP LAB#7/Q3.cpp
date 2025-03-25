#include <iostream>

using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    
public:
    Currency(double amt, string code, string symbol) 
        : amount(amt), currencyCode(code), currencySymbol(symbol) {}

    virtual double convertToBase() const = 0; 

    double convertTo(string targetCurrency) {
        double baseAmount = convertToBase();
        double targetAmount = 0.0;

        if (targetCurrency == "USD") targetAmount = baseAmount;          
        else if (targetCurrency == "EUR") targetAmount = baseAmount * 0.92; 
        else if (targetCurrency == "INR") targetAmount = baseAmount * 280.0;
        else {
            cout << "Exchange rate for " << targetCurrency << " not available." << endl;
            return -1;
        }

        return targetAmount;
    }

    virtual void displayCurrency() const = 0; 

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$") {}

    double convertToBase() const override {
        return amount;  
    }

    void displayCurrency() const override {
        cout << currencySymbol << amount << " " << currencyCode << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€") {}

    double convertToBase() const override {
        return amount / 0.92;  
    }

    void displayCurrency() const override {
        cout << currencySymbol << amount << " " << currencyCode << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "₹") {}

    double convertToBase() const override {
        return amount / 280.0;  
    }

    void displayCurrency() const override {
        cout << currencySymbol << amount << " " << currencyCode << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(100);
    Rupee pkr(10000);

    cout << "\n--- Currency Details ---\n";
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\n--- Currency Conversion ---\n";
    cout << "100 USD in EUR: €" << usd.convertTo("EUR") << endl;
    cout << "100 EUR in USD: $" << eur.convertTo("USD") << endl;
    cout << "10000 INR in USD: $" << inr.convertTo("USD") << endl;
    cout << "100 USD in PKR: ₹" << usd.convertTo("PKR") << endl;

    return 0;
}

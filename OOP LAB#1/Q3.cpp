#include <iostream>

using namespace std;


double roundToTwoDecimalPlaces(double num) {
    return static_cast<int>(num * 100 + 0.5) / 100.0;
}

int main() 
{
    int customerID, unitsConsumed;
    string customerName;
    double chargePerUnit, amountCharged, surcharge = 0, netAmount;


    cout << "Enter Customer ID: ";
    cin >> customerID;
    cin.ignore(); 
    cout << "Enter Customer Name: ";
    getline(cin, customerName);
    cout << "Enter Units Consumed: ";
    cin >> unitsConsumed;

    if (unitsConsumed <= 199)
		{
        chargePerUnit = 16.20;
    } else if (unitsConsumed >= 200 && unitsConsumed < 300) {
        chargePerUnit = 20.10;
    } else if (unitsConsumed >= 300 && unitsConsumed < 500) {
        chargePerUnit = 27.10;
    } else {
        chargePerUnit = 35.90;
    }

    amountCharged = unitsConsumed * chargePerUnit;

    if (amountCharged > 18000) 
	{
        surcharge = amountCharged * 0.15;
    }

    netAmount = amountCharged + surcharge;

    amountCharged = roundToTwoDecimalPlaces(amountCharged);
    surcharge = roundToTwoDecimalPlaces(surcharge);
    netAmount = roundToTwoDecimalPlaces(netAmount);


    cout << "\nCustomer ID: " << customerID << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Units Consumed: " << unitsConsumed << endl;
    cout << "Amount Charges @Rs. " << chargePerUnit << " per unit: " << amountCharged << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << netAmount << endl;

    return 0;
}

#include <iostream>
#include <string>


using namespace std;

double roundToTwoDecimalPlaces(double num)
 {
    return static_cast<int>(num * 100 + 0.5) / 100.0;
}

int main() 
{
    string movieName;
    double adultTicketPrice, childTicketPrice, percentageDonated;
    int adultTicketsSold, childTicketsSold;
    double grossAmount, amountDonated, netSale;

    // Input data
    cout << "Enter movie name: ";
    getline(cin, movieName);
    cout << "Enter adult ticket price: ";
    cin >> adultTicketPrice;
    cout << "Enter child ticket price: ";
    cin >> childTicketPrice;
    cout << "Enter number of adult tickets sold: ";
    cin >> adultTicketsSold;
    cout << "Enter number of child tickets sold: ";
    cin >> childTicketsSold;
    cout << "Enter percentage of gross amount to be donated: ";
    cin >> percentageDonated;

    grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);
    amountDonated = (grossAmount * percentageDonated) / 100;
    netSale = grossAmount - amountDonated;

    grossAmount = roundToTwoDecimalPlaces(grossAmount);
    amountDonated = roundToTwoDecimalPlaces(amountDonated);
    netSale = roundToTwoDecimalPlaces(netSale);


    cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "Movie Name:............................. " << movieName << endl;
    cout << "Number of Tickets Sold:................. " << (adultTicketsSold + childTicketsSold) << endl;
    cout << "Gross Amount:........................... $ " << grossAmount << endl;
    cout << "Percentage of Gross Amount Donated:..... " << percentageDonated << "%" << endl;
    cout << "Amount Donated:......................... $ " << amountDonated << endl;
    cout << "Net Sale:............................... $ " << netSale << endl;

    return 0;
}

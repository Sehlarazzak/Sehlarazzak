#include <iostream>

using namespace std;


double roundToTwoDecimalPlaces(double num) 
{
    return static_cast<int>(num * 100 + 0.5) / 100.0;
}

int main()
 {
    double weightInKg, weightInPounds;

   
    cout << "Enter weight in kilograms: ";
    cin >> weightInKg;

    weightInPounds = weightInKg * 2.2;

    
    weightInKg = roundToTwoDecimalPlaces(weightInKg);
    weightInPounds = roundToTwoDecimalPlaces(weightInPounds);

    cout << "Weight in kilograms: " << weightInKg << " kg" << endl;
    cout << "Weight in pounds: " << weightInPounds << " lbs" << endl;

    return 0;
}

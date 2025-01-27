#include <iostream>
#include <string>


using namespace std;


double roundToTwoDecimalPlaces(double num) {
    return static_cast<int>(num * 100 + 0.5) / 100.0;
}

int main() 
{
    string firstName, lastName;
    double scores[5];
    double total = 0.0, average;

    
    cout << "Enter the student's name (first and last): ";
    cin >> firstName >> lastName;
    cout << "Enter five test scores: ";
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
        total += scores[i]; 
    }

    average = total / 5;
    average = roundToTwoDecimalPlaces(average); 


    cout << "\nStudent name: " << firstName << " " << lastName << endl;
    cout << "Test scores: ";
    for (int i = 0; i < 5; i++) {
        cout << roundToTwoDecimalPlaces(scores[i]) << " "; 
    }
    cout << "\nAverage test score: " << average << endl;

    return 0;
}

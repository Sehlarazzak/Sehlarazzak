#include<iostream>

using namespace std;

class FindSecondHighest {
private:
    float* arr; 
    int size;

public:
    
    FindSecondHighest(float* inputArray, int arraySize) {
        arr = inputArray;
        size = arraySize;
    }

    float getSecondHighest() {
        if (size < 2) {
            cout << "Array must have at least two elements." << endl;
            return -1;
        }

        float highest = arr[0];         
        float secondHighest = -1000000;

        for (int i = 1; i < size; i++) {
            if (arr[i] > highest) {
                secondHighest = highest; 
                highest = arr[i];        
            } else if 
			(arr[i] > secondHighest && arr[i] != highest) {
                secondHighest = arr[i]; 
            }
        }

        if (secondHighest == -1e30f) {
            cout << "No second highest value exists." << endl;
            return -1;
        }

        return secondHighest;
    }
};

int main() {
    float array[20] = {12.5, 45.3, 67.8, 23.9, 89.0, 34.6, 78.1, 56.2, 9.0, 13.4,
                       50.3, 22.8, 18.4, 88.9, 47.3, 25.1, 62.2, 70.5, 33.0, 95.4};

   
    FindSecondHighest finder(array, 20);

   
    cout << "The second highest number is: " << finder.getSecondHighest() << endl;

    return 0;
}

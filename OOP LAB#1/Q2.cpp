#include<iostream>

using namespace std;

class ArraySum 
{
private:
    float* arr; 
    int size;

public:

    ArraySum(float* inputArray, int arraySize)
	{
        arr = inputArray;
        size = arraySize;
    }

    float calculateSum() {
        float sum = 0;
        for (int i = 0; i < size; i++) {
            sum += *(arr + i); 
        }
        return sum;
    }
};

int main()
 {
    float array[10] = {1.2, 2.4, 3.6, 4.8, 5.1, 6.3, 7.5, 8.7, 9.9, 10.0};

    
    ArraySum arraySum(array, 10);

    
    cout << "The sum of the array elements is: " << arraySum.calculateSum() << endl;

    return 0;
}

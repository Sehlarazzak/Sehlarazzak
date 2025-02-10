#include <iostream>

using namespace std;


int* resizeArray(int* arr, int& currentSize, int newSize) {

    int* newArr = new int[newSize];
    
    for (int i = 0; i < currentSize; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;

    currentSize = newSize;
    
    return newArr;
}

int main() {
    int initialSize = 5;
    int currentSize = initialSize;
    int* arr = new int[currentSize];
    int elementCount = 0;
    
    cout << "Enter integers to add to the array (type -1 to stop):" << endl;

    while (true) {
        int input;
        cin >> input;

        if (input == -1) break;  
        
        if (elementCount == currentSize) {
            arr = resizeArray(arr, currentSize, currentSize * 2);
            cout << "Resizing the array to size: " << currentSize << endl;
        }

        arr[elementCount] = input;
        elementCount++;
    }

    if (elementCount < currentSize) {
        arr = resizeArray(arr, currentSize, elementCount);
        cout << "Resizing the array to fit the number of elements: " << elementCount << endl;
    }

    cout << "Final array content:" << endl;
    for (int i = 0; i < elementCount; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}


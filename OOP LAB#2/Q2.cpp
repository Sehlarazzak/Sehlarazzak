#include<iostream>
#include <string>

using namespace std;

int stringToInt(const char *str)
 {
    int num = 0;
    bool negative = false;

    if (*str == '-') {
        negative = true;
        str++;
    }

    while (*str) {
        num = num * 10 + (*str - '0');
        str++;
    }

    return negative ? -num : num;
}

void* addElements(void* array, int size)
 {
    int* arr = static_cast<int*>(array);
    
    for (int i = 0; i < size; ++i) {
        arr[i] += 1;  
    }
    
    return array;  
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        cout << "Please provide at least one integer as an argument!" << endl;
        return 1;
    }

    int size = argc - 1;
    int* array = new int[size];

    for (int i = 0; i < size; ++i) 
	{
        array[i] = stringToInt(argv[i + 1]);  
    }

    void* result = addElements(array, size);

    int* resultArray = static_cast<int*>(result);
    
    cout << "Array after addition operation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << resultArray[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}

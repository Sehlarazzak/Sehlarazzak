#include <iostream>

using namespace std;


int stringToInt(const char *str) 
{
    int num = 0;
    bool negative = false;

    if (*str == '-') 
	{
        negative = true;
        str++;
    }

    while (*str) 
	{
        num = num * 10 + (*str - '0');
        str++;
    }

    return negative ? -num : num;
}

int main(int argc, char *argv[]) 
    {
    if (argc < 2) {
        cout << "Please provide at least one integer as an argument!" << endl;
        return 1;
    }

    int sum = 0;

    for (int i = 1; i < argc; ++i) 
	{
        int num = stringToInt(argv[i]);

        int *ptr = &num;
        sum += *ptr;
    }

    cout << "The sum of the array elements is: " << sum << endl;

    return 0;
}

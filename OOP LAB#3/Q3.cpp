#include<iostream>

using namespace std;


class Glass {
public:
    int LiquidLevel;
    
    Glass() : LiquidLevel(200) {}

    void Drink(int milliliters) 
	{
        if (milliliters > 0 && LiquidLevel >= milliliters) 
		{
            LiquidLevel -= milliliters;
            cout << "You drank " << milliliters << " ml. Remaining: " << LiquidLevel << " ml.\n";
        } 
		else {
            cout << "Not enough liquid to drink that amount!\n";
        }
        
        if (LiquidLevel < 100) 
		{
            Refill();
        }
    }
    
    void Refill() {
        LiquidLevel = 200;
        cout << "Glass refilled to 200 ml.\n";
    }
};

int main() 
{
    Glass glass;
    int amount;
    
    while (true) 
	{
        cout << "Enter amount to drink (or -1 to exit): ";
        cin >> amount;
        if (amount == -1) break;
        glass.Drink(amount);
    }
    
    return 0;
}


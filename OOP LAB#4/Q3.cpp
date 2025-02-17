#include <iostream>
#include <string>

class Invoice
{
private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(std::string pNumber, std::string pDescription, int qty, double price) 
	{
        partNumber = pNumber;
        partDescription = pDescription;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0) ? price : 0.0;
    }

    double getInvoiceAmount() const 
	{
        return quantity * pricePerItem;
    }

    void displayInvoice() const 
	{
        std::cout << "Part Number: " << partNumber << "\n"
                  << "Part Description: " << partDescription << "\n"
                  << "Quantity: " << quantity << "\n"
                  << "Price per Item: " << pricePerItem << "\n"
                  << "Total Invoice Amount: " << getInvoiceAmount() << "\n";
    }
};

int main() 
{
    Invoice invoice("1234", "Hammer", 5, 10.99);
    invoice.displayInvoice();
    
    return 0;
}


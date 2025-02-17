#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string publisher;
    double price;
    int stock;

public:
    Book(std::string t, std::string a, std::string p, double pr, int s)
        : title(t), author(a), publisher(p), price(pr), stock(s) {}

    bool isMatch(std::string t, std::string a) const 
	{
        return (title == t && author == a);
    }

    void displayBook() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Publisher: " << publisher << "\n"
                  << "Price: " << price << "\n"
                  << "Stock: " << stock << "\n";
    }
	
    void sellBook(int quantity) 
	{
        if (quantity <= stock) 
		{
            std::cout << "Total Cost: " << price * quantity << "\n";
            stock -= quantity;
        } else {
            std::cout << "Required copies not in stock." << "\n";
        }
    }
};

int main() {
    std::vector<Book> inventory = {
        {"C++ Programming", "Bjarne Stroustrup", "Addison-Wesley", 45.99, 10},
        {"Effective C++", "Scott Meyers", "O'Reilly", 39.99, 5},
        {"The C Programming Language", "Brian Kernighan", "Prentice Hall", 49.99, 8}
    };

    std::string searchTitle, searchAuthor;
    std::cout << "Enter book title: ";
    std::getline(std::cin, searchTitle);
    std::cout << "Enter author name: ";
    std::getline(std::cin, searchAuthor);

    bool found = false;
    for (Book &book : inventory) {
        if (book.isMatch(searchTitle, searchAuthor)) {
            found = true;
            book.displayBook();
            int copies;
            std::cout << "Enter number of copies required: ";
            std::cin >> copies;
            book.sellBook(copies);
            break;
        }
    }

    if (!found) 
	{
        std::cout << "Book not available in inventory." << std::endl;
    }

    return 0;
}




#include<iostream>

using namespace std;

class Book {
private:
    string bookName;
    string ISBN;
    string authorName;
    string publisher;
    
public:
    Book(string bookName, string ISBN, string authorName, string publisher) 
	{
        this->bookName = bookName;
        this->ISBN = ISBN;
        this->authorName = authorName;
        this->publisher = publisher;
    }

    string getBookName() { return this->bookName; }
    string getISBN() { return this->ISBN; }
    string getAuthorName() { return this->authorName; }
    string getPublisher() { return this->publisher; }

    string getBookInfo() 
	{
        return "Book Name: " + this->bookName + "\nISBN: " + this->ISBN + "\nAuthor: " + this->authorName + "\nPublisher: " + this->publisher;
    }
};
int main() {
    Book books[5] = {
        Book("The Great Gatsby", "978-0743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("1984", "978-0451524935", "George Orwell", "Signet"),
        Book("To Kill a Mockingbird", "978-0061120084", "Harper Lee", "Harper Perennial"),
        Book("The Catcher in the Rye", "978-0316769488", "J.D. Salinger", "Little, Brown"),
        Book("Moby-Dick", "978-1503280786", "Herman Melville", "CreateSpace")
    };

    for (int i = 0; i < 5; i++) 
	{
        cout << books[i].getBookInfo() << "\n\n";
    }
    
    return 0;
}

#include <iostream>
using namespace std;

class Book {
protected:
    string genre;

public:
    Book(string g) : genre(g) {}
    virtual void display() const = 0; // Pure virtual function
    virtual ~Book() {}
};

class Novel : public Book {
private:
    string title;
    string author;

public:
    Novel(string t, string a) : Book("Novel"), title(t), author(a) {}
    void display() const override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n\n";
    }
};

class Mystery : public Book {
private:
    string title;
    string author;

public:
    Mystery(string t, string a) : Book("Mystery"), title(t), author(a) {}
    void display() const override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n\n";
    }
};

int main() {
    Novel novel("Pride and Prejudice", "Jane Austen");
    Mystery mystery("The Hound of the Baskervilles", "Arthur Conan Doyle");
    novel.display();
    mystery.display();
    
    return 0;
}


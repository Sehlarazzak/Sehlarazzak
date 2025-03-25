#include <iostream>
#include <vector>

using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() const {
        cout << "\nTitle: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
             << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
    
    virtual ~Media() {} 
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string a, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration; // In minutes
    string rating;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(string t, string pubDate, string id, string pub, int issue)
        : Media(t, pubDate, id, pub), issueNumber(issue) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class Library {
private:
    vector<Media *> collection;

public:
    void addMedia(Media *m) {
        collection.push_back(m);
    }

    void searchMedia(string searchTitle) {
        for (const auto &item : collection) {
            if (item->getTitle() == searchTitle) {
                cout << "\nMedia Found:\n";
                item->displayInfo();
                return;
            }
        }
        cout << "Media not found.\n";
    }

    void searchMedia(int pubYear) {
        string yearStr = to_string(pubYear);
        for (const auto &item : collection) {
            if (item->getPublicationDate().find(yearStr) != string::npos) {
                cout << "\nMedia Found:\n";
                item->displayInfo();
                return;
            }
        }
        cout << "Media not found.\n";
    }

    void displayAllMedia() {
        cout << "\n--- Library Collection ---\n";
        for (const auto &item : collection) {
            item->displayInfo();
        }
    }

    ~Library() {
        for (auto &item : collection)
            delete item;
    }
};

int main() {
    Library myLibrary;

    myLibrary.addMedia(new Book("C++ Programming", "2022", "B101", "Tech Publishers", "Bjarne Stroustrup", "978-0-321", 450));

    myLibrary.addMedia(new DVD("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 148, "PG-13"));

    myLibrary.addMedia(new CD("Thriller", "1982", "C303", "Epic Records", "Michael Jackson", 9, "Pop"));

    myLibrary.addMedia(new Magazine("National Geographic", "2023", "M404", "NatGeo", 245));

    myLibrary.displayAllMedia();

    myLibrary.searchMedia("Inception");

    myLibrary.searchMedia(1982);

    cout << "\n--- Checking Out a Book ---\n";
    myLibrary.searchMedia("C++ Programming");
    myLibrary.searchMedia("C++ Programming"); 

    return 0;
}


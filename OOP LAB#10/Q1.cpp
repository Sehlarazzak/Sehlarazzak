#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class EncryptorDecryptor {
private:
    string text;
    string encryptedText;
    string decryptedText;
    string filename;

public:
    EncryptorDecryptor(string file) {
        filename = file;
    }

    void getInput() {
        cout << "Enter String: ";
        getline(cin, text);
    }

    void encrypt() {
        encryptedText = "";
        for (size_t i = 0; i < text.length(); i++) {
            char ch = text[i];
            ch = ch + (i + 1); 
            encryptedText += ch;
        }
    }

    void saveToFile() {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << encryptedText;
            outFile.close();
            cout << "Encrypted text inserted in file.\n";
        } else {
            cout << "Unable to open file for writing.\n";
        }
    }

    void readFromFile() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            getline(inFile, encryptedText); 
            inFile.close();
        } else {
            cout << "Unable to open file for reading.\n";
        }
    }

    void decrypt() {
        decryptedText = "";
        for (size_t i = 0; i < encryptedText.length(); i++) {
            char ch = encryptedText[i];
            ch = ch - (i + 1); 
            decryptedText += ch;
        }
    }

    void displayResults() {
        cout << "Normal Text: " << text << endl;
        cout << "Encrypted Text: " << encryptedText << endl;
        cout << "Decrypted Text: " << decryptedText << endl;
    }
};

int main() {
    EncryptorDecryptor ed("encrypted.txt");

    ed.getInput();
    ed.encrypt();
    ed.saveToFile();
    ed.readFromFile();
    ed.decrypt();
    ed.displayResults();

    return 0;
}


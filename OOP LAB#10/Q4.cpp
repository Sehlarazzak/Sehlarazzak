#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>  
using namespace std;
namespace fs = std::filesystem;

class Logger {
private:
    string baseFileName = "log";
    string extension = ".txt";
    int fileIndex = 1;
    size_t maxFileSize = 1024 * 1024; 
    ofstream logFile;
	
    string getCurrentFileName() {
        return baseFileName + to_string(fileIndex) + extension;
    }

    void openLogFile() {
        logFile.open(getCurrentFileName(), ios::app);
    }

    void checkRotation() {
        logFile.flush(); 
        string currentFile = getCurrentFileName();
        if (fs::exists(currentFile) && fs::file_size(currentFile) >= maxFileSize) {
            logFile.close();
            ++fileIndex;
            openLogFile();
        }
    }

public:
    Logger() {
        openLogFile();
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void writeLog(const string& message) {
        if (!logFile.is_open()) {
            openLogFile();
        }
        logFile << message << endl;
        checkRotation();
    }
};

int main() {
    Logger logger;

    for (int i = 0; i < 50000; ++i) {
        logger.writeLog("Log Entry Number: " + to_string(i+1));
    }

    cout << "Logs written successfully with rotation when exceeding size!" << endl;
    return 0;
}

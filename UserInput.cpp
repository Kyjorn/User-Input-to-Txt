#include <iostream>;
#include <fstream>;
#include <string>;
#include <algorithm>;
using namespace std;

//reverse method

int main () {

    //variables
    string userIn;
    string userFile;
    string reverseUserFile; 

    //gets userIn
    cout << "Enter text to be appended in the file: ";
    getline(cin, userIn);

    //appends CSC450_CT5_mod5
    ofstream outFile("CSC450_CT5_mod5.txt", ios::app);
    if (outFile.is_open()) {
        outFile << userIn << endl;
        outFile.close();
    } else {
        cout << "Error opening file for appending.\n";
        return 1;
    }

    //read and reverses content
    ifstream inFile("CSC450_CT5_mod5.txt");
    string content; // Define content to store the reversed lines
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            reverse(line.begin(), line.end());
            content += line + "\n"; // Append reversed line to content
        }
        inFile.close();
    } else {
        cout << "Error opening file for reading.\n";
        return 1;
    }

    //writes reversed content to new file
    ofstream outFileReverse("CSC450_CT5_mod5_reverse.txt");
    if (outFileReverse.is_open()) {
        outFileReverse << content;
        outFileReverse.close();
    } else {
        cout << "Error opening file for writing.\n";
        return 1;
    }
    cout << "Reversed content written to CSC450_CT5_mod5_reverse.txt\n";
return 0;
}


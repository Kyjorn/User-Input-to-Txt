#include <iostream>;
#include <fstream>;
#include <string>;
#include <algorithm>;
using namespace std;

//reverse method

int main () {

    //variables
    string userIn;
    string userFile = CSC450_CT5_mod5.txt;
    string reverseUserFile = CSC450_CT5_mod5_reverse.txt; 

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
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            reverse(line.begin(), line.end());
            outFile << line << endl;
        }
        inFile.close();
    } else {
        cout << "Error opening file for reading.\n";
        return 1;
    }

return 0;
}



// Lab 1 - Data Visualization.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <vector>
using namespace std;

int main() {

    // variables

    string dataTitle;
    string col1Header;
    string col2Header;

    string dataPoint;
    string stringDataPoint;
    string beforeComma;
    int intDataPoint;
    string afterComma;

    vector<string> authorNames;
    vector<int> novelNumbers;

    bool error = false;

    // titles' names input/output

    cout << "Enter a title for the data:" << endl;
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, col1Header);
    cout << "You entered: " << col1Header << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, col2Header);
    cout << "You entered: " << col2Header << endl;

    while (dataPoint != "-1") {

        error = false;

        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, dataPoint);

        if (dataPoint == "-1") {

            break;
        }

        char comma = dataPoint.find(",");
        beforeComma = dataPoint.substr(0, comma);
        afterComma = dataPoint.substr(comma + 1);

        if (comma == string::npos) {

            cout << "Error: No comma in string." << endl;

        }

        if (comma != string::npos) {

            comma = dataPoint.find(',', comma + 1);
            if (comma != string::npos) {

                cout << "Error: Too many commas in input." << endl;
                error = true;
            }

            if (error == false) {

                try {

                    intDataPoint = stoi(afterComma);

                    cout << "Data string: " << beforeComma << endl;
                    cout << "Data integer: " << intDataPoint << endl;

                    //cout << beforeComma << endl;
                    //cout << intDataPoint << endl;

                    authorNames.push_back(beforeComma);
                    novelNumbers.push_back(intDataPoint);
                }
                catch (invalid_argument arg) {

                    cout << "Error: Comma not followed by an integer." << endl;
                }

            }

        }

    }

    cout << endl << setw(33) << dataTitle << endl;
    cout << setw(20) << left << col1Header << "|";
    cout << setw(23) << right << col2Header << endl;
    cout << setfill('-') << setw(44) << "" << endl;
    cout << setfill(' ');

    for (int vn = 0; vn < authorNames.size(); vn++) {

        cout << setw(20) << left << authorNames[vn] << "|";
        cout << setw(23) << right << novelNumbers[vn] << endl;
    }

    cout << endl;

    for (int v = 0; v < novelNumbers.size(); v++) {

        cout << setw(20) << right << authorNames[v] << " ";

        for (int n = 0; n < novelNumbers[v]; n++) {

            cout << "*";
        }

        cout << endl;
    }

    return 0;
}

/* Overall flow of the program:
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2

   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces

   Print out data in table format

   Print out data in chart format */

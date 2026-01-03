#include <iostream>
#include <fstream>
#include <string>
#include "labtest.h"
using namespace std;
void addLabTest() {
    int n;
    cout << "Please enter number of tests you want to add: ";
    cin >> n;
    cin.ignore();
    ofstream fout("labreport.csv", ios::app);

    for(int i = 1; i <= n; i++) {
        string testid, patientname, testname, testdate;
        cout << "\nADD LAB TEST " << i << endl;
        cout << "Please enter test ID: ";
        cin >> testid;
        cin.ignore();
        cout << "Please enter patient name: ";
        getline(cin, patientname);
        cout << "Please enter test name: ";
        getline(cin, testname);
        cout << "Please enter test date: ";
        getline(cin, testdate);

        fout << testid << "," << patientname << "," << testname << "," 
             << testdate << ",pending" << endl;
    }

    fout.close();
    cout << "Lab test records added successfully!\n";
}


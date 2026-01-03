#include <iostream>
#include <fstream>
#include <sstream>
#include "doctor.h"

using namespace std;

void addDoctor() {
    ofstream file("doctors.csv", ios::app);

    int id;
    string name, education, specialization, category;

    cout << "Enter Doctor ID: ";
    cin >> id;

    cout << "Enter Doctor Name: ";
    cin >> name;

    cout << "Enter Education: ";
    cin >> education;

    cout << "Enter Specialization: ";
    cin >> specialization;

    cout << "Enter Category: ";
    cin >> category;

    file << id << "," << name << "," << education << ","
         << specialization << "," << category << "\n";

    file.close();
    cout << "Doctor Added Successfully!\n";
}

void viewDoctor() {
    ifstream file("doctors.csv");

    if (!file) {
        cout << "File not found!\n";
        return;
    }

    string line;
    cout << "\nID, Name, Education, Specialization, Category\n";

    while (getline(file, line)) {
        if (!line.empty())
            cout << line << endl;
    }

    file.close();
}
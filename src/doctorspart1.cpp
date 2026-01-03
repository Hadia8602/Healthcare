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

void deleteDoctor() {
    ifstream file("doctors.csv");
    ofstream temp("temp.csv");

    int id, did;
    bool found = false;
    string line;

    cout << "Enter Doctor ID to delete: ";
    cin >> id;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> did;

        if (did != id) {
            temp << line << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("doctors.csv");
    rename("temp.csv", "doctors.csv");

    if (found)
        cout << "Doctor Deleted Successfully!\n";
    else
        cout << "Doctor Not Found!\n";
}

void updateDoctor() {
    ifstream file("doctors.csv");
    ofstream temp("temp.csv");

    int id, did;
    string name, education, specialization, category;
    bool found = false;
    string line;

    cout << "Enter Doctor ID to update: ";
    cin >> id;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> did;

        if (did == id) {
            found = true;

            cout << "Enter New Name: ";
            cin >> name;

            cout << "Enter New Education: ";
            cin >> education;

            cout << "Enter New Specialization: ";
            cin >> specialization;

            cout << "Enter New Category: ";
            cin >> category;

            temp << id << "," << name << "," << education << ","
                 << specialization << "," << category << "\n";
        } else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("doctors.csv");
    rename("temp.csv", "doctors.csv");

    if (found)
        cout << "Doctor Updated Successfully!\n";
    else
        cout << "Doctor Not Found!\n";
}




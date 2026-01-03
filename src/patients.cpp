#include <iostream>
#include <fstream>
#include <string>
#include "patient.h"
using namespace std;

void addPatient()
{
    ofstream file("patients.csv", ios::app);

    if (!file)
    {
        cout << "File error!\n";
        return;
    }

    string id, name, age, gender, contact, disease;

    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Contact: ";
    cin >> contact;
    cout << "Enter Disease: ";
    cin >> disease;

    file << id << "," << name << "," << age << ","
         << gender << "," << contact << "," << disease << endl;

    file.close();
    cout << "Patient added successfully.\n";
}

void viewPatient() {
    ifstream file("patients.csv"); 
    string id, name, age, gender, contact, disease, searchId;
    bool found = false;

    if (!file.is_open()) {
        cout << "Error: Could not open database.\n";
        return;
    }

    cout << "Enter Patient ID to search: ";
    cin >> searchId;

    while (getline(file, id, ',')) {
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, gender, ',');
        getline(file, contact, ',');
        getline(file, disease); 

        if (id == searchId) {
            found = true;
            cout << "\n--- Patient Record Found ---" << endl;
            cout << "ID:      " << id << endl;
            cout << "Name:    " << name << endl;
            cout << "Age:     " << age << endl;
            cout << "Gender:  " << gender << endl;
            cout << "Contact: " << contact << endl;
            cout << "Disease: " << disease << endl;
            break; 
        }
    }

    file.close();

    if (!found) {
        cout << "Patient not found.\n";
    }
}
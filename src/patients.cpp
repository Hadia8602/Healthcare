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
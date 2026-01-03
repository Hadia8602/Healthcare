#include<iostream>
#include<fstream>
#include<string>
#include "billing.h"

using namespace std;

void addBill()
{
    ofstream file("billing.csv", ios::app);

    int bill_id;
    string patient_name;
    float service, doctor, pharmacy, lab, room, total;

    cout << "ENTER BILL ID: ";
    cin >> bill_id;
    cin.ignore();

    cout << "ENTER PATIENT NAME: ";
    getline(cin, patient_name);

    cout << "SERVICE CHARGES: ";
    cin >> service;
    cout << "DOCTOR FEE: ";
    cin >> doctor;
    cout << "PHARMACY CHARGES: ";
    cin >> pharmacy;
    cout << "LAB CHARGES: ";
    cin >> lab;
    cout << "ROOM CHARGES: ";
    cin >> room;

    total = service + doctor + pharmacy + lab + room;

    file << bill_id << ","
         << patient_name << ","
         << service << ","
         << doctor << ","
         << pharmacy << ","
         << lab << ","
         << room << ","
         << total << "\n";

    file.close();
    cout << "Bill added successfully!\n";
}


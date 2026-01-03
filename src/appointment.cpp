#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "appointment.h"

using namespace std;

void addAppointment() {
    string id, patientname, docname, date, time, status;

    cout << "Enter Appointment ID: ";
    getline(cin, id);
    cout << "Enter Patient Name: ";
    getline(cin, patientname);
    cout << "Enter Doctor Name: ";
    getline(cin, docname);
    cout << "Enter Date (dd/mm/yy): ";
    getline(cin, date);
    cout << "Enter Time: ";
    getline(cin, time);
    status = "Scheduled";

    ofstream file("appointmentrecord.csv", ios::app);
    if (!file) {
        cout << "Error opening file"<<endl;
        return;
    }
    file << id << "," << patientname << "," << docname << ","<< date << "," << time << "," << status << endl;

    file.close();
    cout << "Appointment added successfully"<<endl;
}
void viewAppointment() {
    ifstream file("appointmentrecord.csv");
    if (!file) {
        cout << "Error opening file"<<endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
void updateAppointment() {
    string searchid, line;
    cout << "Enter Appointment ID to update: ";
    getline(cin, searchid);

    ifstream file("appointmentrecord.csv");
    if (!file) {
        cout << "Error opening file"<<endl;
        return;
    }
    ofstream temp("temp.csv");
    bool found = false;
    while (getline(file, line)) {
        string id, patientname, docname, date, time, status;
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, patientname, ',');
        getline(ss, docname, ',');
        getline(ss, date, ',');
        getline(ss, time, ',');
        getline(ss, status, ',');

        if (id == searchid) {
            cout << "Enter Patient Name: ";
            getline(cin, patientname);
            cout << "Enter Doctor Name: ";
            getline(cin, docname);
            cout << "Enter Date (dd/mm/yy): ";
            getline(cin, date);
            cout << "Enter Time: ";
            getline(cin, time);
            status = "Scheduled";

            temp << id << "," << patientname << "," << docname << ","<< date << "," << time << "," << status << endl;
            found = true;
        } else {
            temp << line << endl;
        }
    }
    file.close();
    temp.close();

    remove("appointmentrecord.csv");
    rename("temp.csv", "appointmentrecord.csv");

    if (found)
        cout << "Appointment updated successfully"<<endl;
    else
        cout << "Appointment ID not found"<<endl;
}


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
        cout << "Error opening file\n";
        return;
    }
    file << id << "," << patientname << "," << docname << ","<< date << "," << time << "," << status << endl;

    file.close();
    cout << "Appointment added successfully"<<endl;
}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "staff.h"

using namespace std;

void addStaff() {
    ofstream file("staffs.csv", ios::app);

    int staff_id;
    string name, gender, department, profession, available, shift;

    cout << "Enter Staff ID: ";
    cin >> staff_id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Profession: ";
    getline(cin, profession);

    cout << "Is Staff Available: ";
    getline(cin, available);

    cout << "Enter Shift: ";
    getline(cin, shift);

    file << staff_id << "," << name << "," << gender << ","
         << department << "," << profession << ","
         << available << "," << shift << "\n";

    file.close();
    cout << "Staff added successfully!\n";
}

void viewStaff() {
    ifstream file("staffs.csv");
    string line;

    if (!file) {
        cout << "Error opening file\n";
        return;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void updateStaff() {
    ifstream file("staffs.csv");
    ofstream temp("temp.csv");

    int staff_id, searchid;
    string name, gender, department, profession, available, shift;
    bool found = false;
    string line;

    cout << "Enter Staff ID to update: ";
    cin >> searchid;
    cin.ignore();

    while (getline(file, line)) {
        stringstream ss(line);

        ss >> staff_id;
        ss.ignore();

        getline(ss, name, ',');
        getline(ss, gender, ',');
        getline(ss, department, ',');
        getline(ss, profession, ',');
        getline(ss, available, ',');
        getline(ss, shift, ',');

        if (staff_id == searchid) {
            found = true;

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Gender: ";
            getline(cin, gender);

            cout << "Enter New Department: ";
            getline(cin, department);

            cout << "Enter New Profession: ";
            getline(cin, profession);

            cout << "Is Staff Available: ";
            getline(cin, available);

            cout << "Enter New Shift: ";
            getline(cin, shift);
        }

        temp << staff_id << "," << name << "," << gender << ","
             << department << "," << profession << ","
             << available << "," << shift << "\n";
    }

    file.close();
    temp.close();

    remove("staffs.csv");
    rename("temp.csv", "staffs.csv");

    if (found)
        cout << "Staff updated successfully\n";
    else
        cout << "Staff ID not found\n";
}

void deleteStaff() {
    ifstream file("staffs.csv");
    ofstream temp("temp.csv");

    int staff_id, searchid;
    string name, gender, department, profession, available, shift;
    bool found = false;
    string line;

    cout << "Enter Staff ID to delete: ";
    cin >> searchid;
    cin.ignore();

    while (getline(file, line)) {
        stringstream ss(line);

        ss >> staff_id;
        ss.ignore();

        getline(ss, name, ',');
        getline(ss, gender, ',');
        getline(ss, department, ',');
        getline(ss, profession, ',');
        getline(ss, available, ',');
        getline(ss, shift, ',');

        if (staff_id != searchid) {
            temp << staff_id << "," << name << "," << gender << ","
                 << department << "," << profession << ","
                 << available << "," << shift << "\n";
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("staffs.csv");
    rename("temp.csv", "staffs.csv");

    if (found)
        cout << "Staff deleted successfully\n";
    else
        cout << "Staff ID not found\n";
}

void staffMenu() {
    int choice;

    do {
        cout << "\n===== Staff Management System =====\n";
        cout << "1. Add Staff\n";
        cout << "2. View Staff\n";
        cout << "3. Update Staff\n";
        cout << "4. Delete Staff\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addStaff(); break;
            case 2: viewStaff(); break;
            case 3: updateStaff(); break;
            case 4: deleteStaff(); break;
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);
}
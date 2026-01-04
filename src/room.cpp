#include <iostream>
#include <fstream>
#include <sstream>
#include "room.h"

using namespace std;

struct Room {
    int roomNo;
    string wardType;
    int roomAvailable;
    int washroom;
    int machinery;
    int oxygen;
    int beds;
    int chairs;
};

void addRoom() {
    ofstream file("rooms.csv", ios::app);
    Room r;

    cout << "\nEnter Room Number: ";
    cin >> r.roomNo;
    cout << "Enter Ward Type (ICU/OT/Ward): ";
    cin >> r.wardType;
    cout << "Room Available (1=Yes, 0=No): ";
    cin >> r.roomAvailable;
    cout << "Washroom Available (1/0): ";
    cin >> r.washroom;
    cout << "Machinery Available (1/0): ";
    cin >> r.machinery;
    cout << "Oxygen Cylinder Available (1/0): ";
    cin >> r.oxygen;
    cout << "Number of Beds: ";
    cin >> r.beds;
    cout << "Number of Chairs: ";
    cin >> r.chairs;

    file << r.roomNo << "," << r.wardType << "," << r.roomAvailable << ","
         << r.washroom << "," << r.machinery << "," << r.oxygen << ","
         << r.beds << "," << r.chairs << "\n";

    file.close();
    cout << "\nRoom Added Successfully!\n";
}

void viewRooms() {
    ifstream file("rooms.csv");
    if (!file) {
        cout << "No room data found.\n";
        return;
    }

    string line;
    cout << "\nRoomNo,WardType,Available,Washroom,Machinery,Oxygen,Beds,Chairs\n";

    while (getline(file, line)) {
        if (!line.empty())
            cout << line << endl;
    }

    file.close();
}

void updateRoom() {
    ifstream file("rooms.csv");
    ofstream temp("temp.csv");

    int roomNo;
    cout << "\nEnter Room Number to Update: ";
    cin >> roomNo;

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Room r;

        getline(ss, token, ','); r.roomNo = stoi(token);
        getline(ss, r.wardType, ',');
        getline(ss, token, ','); r.roomAvailable = stoi(token);
        getline(ss, token, ','); r.washroom = stoi(token);
        getline(ss, token, ','); r.machinery = stoi(token);
        getline(ss, token, ','); r.oxygen = stoi(token);
        getline(ss, token, ','); r.beds = stoi(token);
        getline(ss, token, ','); r.chairs = stoi(token);

        if (r.roomNo == roomNo) {
            found = true;
            cout << "Enter New Room Availability (1/0): "; cin >> r.roomAvailable;
            cout << "Enter Washroom (1/0): "; cin >> r.washroom;
            cout << "Enter Machinery (1/0): "; cin >> r.machinery;
            cout << "Enter Oxygen (1/0): "; cin >> r.oxygen;
            cout << "Enter Beds: "; cin >> r.beds;
            cout << "Enter Chairs: "; cin >> r.chairs;
        }

        temp << r.roomNo << "," << r.wardType << "," << r.roomAvailable << ","
             << r.washroom << "," << r.machinery << "," << r.oxygen << ","
             << r.beds << "," << r.chairs << "\n";
    }

    file.close();
    temp.close();

    remove("rooms.csv");
    rename("temp.csv", "rooms.csv");

    if (found)
        cout << "\nRoom Updated Successfully!\n";
    else
        cout << "\nRoom Not Found!\n";
}

void deleteRoom() {
    ifstream file("rooms.csv");
    ofstream temp("temp.csv");

    int roomNo;
    cout << "\nEnter Room Number to Delete: ";
    cin >> roomNo;

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        int rNo;
        getline(ss, token, ','); rNo = stoi(token);
        if (rNo != roomNo) temp << line << endl;
        else found = true;
    }

    file.close();
    temp.close();

    remove("rooms.csv");
    rename("temp.csv", "rooms.csv");

    if (found)
        cout << "\nRoom Deleted Successfully!\n";
    else
        cout << "\nRoom Not Found!\n";
}

void roomMenu() {
    int choice;
    do {
        cout << "\n===== Room Management =====\n";
        cout << "1. Add Room\n2. View Rooms\n3. Update Room\n4. Delete Room\n5. Back to Main Menu\n";
        cout << "Enter choice: "; cin >> choice;

        switch(choice) {
            case 1: addRoom(); break;
            case 2: viewRooms(); break;
            case 3: updateRoom(); break;
            case 4: deleteRoom(); break;
            case 5: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

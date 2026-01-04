#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "appointment.h"

using namespace std;

void addAppointment(){
    string id, patientname, docname, date, time, status;

    cout<<"Enter Appointment ID: ";
    getline(cin, id);
    cout<<"Enter Patient Name: ";
    getline(cin, patientname);
    cout<<"Enter Doctor Name: ";
    getline(cin, docname);
    cout<<"Enter Date (dd/mm/yy): ";
    getline(cin, date);
    cout<<"Enter Time: ";
    getline(cin, time);
    status="Scheduled";

    ofstream file("appointmentrecord.csv", ios::app);
    if(!file){
        cout<<"Error opening file"<<endl;
        return;
    }

    file<<id<<","<<patientname<<","<<docname<<","<<date<<","<<time<<","<<status<<endl;

    file.close();
    cout<<"Appointment added successfully"<<endl;
}
void viewAppointment(){

    ifstream file("appointmentrecord.csv");
    if(!file){
        cout<<"Error opening file"<<endl;
        return;
    }
    string line;
    while(getline(file, line)){
        cout<<line<<endl;
    }
    file.close();
}
void updateAppointment(){

    string searchid, line;
    cout<<"Enter Appointment ID to update: ";
    getline(cin, searchid);

    ifstream file("appointmentrecord.csv");
    if(!file){
        cout<<"Error opening file"<<endl;
        return;
    }
    ofstream temp("temp.csv");
    bool found=false;
    while(getline(file, line)){

        string id, patientname, docname, date, time, status;
        stringstream ss(line);
        getline(ss,id,',');
        getline(ss,patientname,',');
        getline(ss,docname,',');
        getline(ss,date,',');
        getline(ss,time,',');
        getline(ss,status,',');

        if(id==searchid){
            cout<<"Enter Patient Name: ";
            getline(cin, patientname);
            cout<<"Enter Doctor Name: ";
            getline(cin, docname);
            cout<<"Enter Date (dd/mm/yy): ";
            getline(cin, date);
            cout<<"Enter Time: ";
            getline(cin, time);
            status="Scheduled";

            temp<<id<<","<<patientname<<","<<docname<<","<<date<<","<<time<<","<<status<<endl;
            found=true;
        }
        else{
            temp<<line<<endl;
        }
    }
    file.close();
    temp.close();

    remove("appointmentrecord.csv");
    rename("temp.csv", "appointmentrecord.csv");

    if(found)
        cout<<"Appointment updated successfully"<<endl;
    else
        cout<<"Appointment ID not found"<<endl;
}
void deleteAppointment(){

    string searchid, line;
    cout<<"Enter Appointment ID to delete: ";
    getline(cin, searchid);

    ifstream file("appointmentrecord.csv");
    if(!file){
        cout<<"Error opening file"<<endl;
        return;
    }
    ofstream temp("temp.csv");
    bool found = false;
    while(getline(file, line)){
        string id;
        stringstream ss(line);
        getline(ss, id, ',');
        if(id!=searchid) {
            temp<<line<<endl;
        } 
        else{
            found=true;
        }
    }
    file.close();
    temp.close();
    remove("appointmentrecord.csv");
    rename("temp.csv", "appointmentrecord.csv");

    if(found)
        cout<<"Appointment deleted successfully"<<endl;
    else
        cout<<"Appointment ID not found"<<endl;
}
void appointmentMenu() {
    int choice;

    do {
        cout<<"Appointment Management System"<<endl;
        cout<<"1.Add Appointment"<<endl;
        cout<<"2.View Appointments"<<endl;
        cout<<"3.Update Appointment"<<endl;
        cout<<"4.Delete Appointment"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch (choice) {
            case 1: 
                addAppointment(); 
                break;
            case 2: 
                viewAppointment();
                break;
            case 3: 
                updateAppointment();
                break;
            case 4: 
                deleteAppointment(); 
                break;
            case 5: 
                cout<<"Exit"<<endl;
                break;
            default:
                cout << "Invalid choice\n";
        }
    } 
    while (choice!=5);
    return 0;
}



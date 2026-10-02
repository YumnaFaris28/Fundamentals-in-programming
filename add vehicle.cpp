#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int MAX_VEHICLES = 100; // Maximum number of vehicles

int main()
{
    string vehicleNames[MAX_VEHICLES];
    string licensePlates[MAX_VEHICLES];
    int vehicleCount = 0;
    char choice;
    
    cout << "---Add Vehicle---" << endl;
    
    do {
        if(vehicleCount >= MAX_VEHICLES) {
            cout << "Maximum vehicle limit reached!" << endl;
            break;
        }
        
        cout << "Vehicle Name: ";
        getline(cin, vehicleNames[vehicleCount]);
        
        cout << "License plate number: ";
        getline(cin, licensePlates[vehicleCount]);
        
        // Check if both fields are not empty
        if(!vehicleNames[vehicleCount].empty() && !licensePlates[vehicleCount].empty())
        {
            cout << "Name: " << vehicleNames[vehicleCount] << endl;
            cout << "Plate: " << licensePlates[vehicleCount] << endl;
            cout << vehicleNames[vehicleCount] << " Added to array successfully!!!" << endl;
            vehicleCount++;
        }
        else {
            cout << "Error: Name and license plate are required!!" << endl;
        }
        
        cout << "Add another vehicle? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        
    } while (choice == 'y' || choice == 'Y');
    
    // Save all vehicles to file at once
    if(vehicleCount > 0) {
        ofstream outfile("vehicle.txt", ios::app);
        if(outfile.is_open()) {
            for(int i = 0; i < vehicleCount; i++) {
                outfile << vehicleNames[i] << "," << licensePlates[i] << endl;
            }
            outfile.close();
            cout << "All " << vehicleCount << " vehicles saved to file successfully!" << endl;
        } else {
            cout << "Error: Could not save to file!" << endl;
        }
    } else {
        cout << "No vehicles to save." << endl;
    }
    
    // Display all vehicles from array
    cout << "\n---All Vehicles in Array---" << endl;
    for(int i = 0; i < vehicleCount; i++) {
        cout << (i+1) << ". " << vehicleNames[i] << " - " << licensePlates[i] << endl;
    }
    
    return 0;
}
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int MAX_VEHICLES = 25;

int main()
{
    int id[MAX_VEHICLES] = {2000, 2001, 2002, 2003, 2004, 2005};
    string category[MAX_VEHICLES] = {"car", "bus", "bike", "3wheeler", "truck", "van"};
    string seaterType[MAX_VEHICLES] = {"6-seater", "20-seater", "2-seater", "4-seater", "10-seater", "9-seater"};
    bool availability[MAX_VEHICLES] = {true, true, true, false, true, false};
    
    int vehicleCount = 6; 
    
    // Load data from file
    ifstream infile("vehicles.txt");
    if (infile.is_open())
    {
        vehicleCount = 0;
        int tempAvailability;
        string line;
        
        while (vehicleCount < MAX_VEHICLES && 
               infile >> id[vehicleCount] >> category[vehicleCount] >> seaterType[vehicleCount] >> tempAvailability)
        {
            availability[vehicleCount] = (tempAvailability != 0);
            vehicleCount++;
        }
        infile.close();
        cout << "Data loaded from file successfully. Loaded " << vehicleCount << " vehicles." << endl;
    } 
    else 
    {
        cout << "No existing data file found. Using default data with " << vehicleCount << " vehicles." << endl;
    }

    // DEBUG: Show ALL vehicles currently in system
    cout << "\n=== CURRENT VEHICLES IN SYSTEM ===" << endl;
    if (vehicleCount == 0) {
        cout << "No vehicles available!" << endl;
    } else {
        for(int i = 0; i < vehicleCount; i++) {
            cout << "ID: " << id[i] << " | " << category[i] << " | " << seaterType[i] << " | " 
                 << (availability[i] ? "Available" : "Not Available") << endl;
        }
    }
    cout << "==================================" << endl;

    int choice;
    do
    {
        cout << "\n---Vehicle Management System---" << endl;
        cout << "1. Enquire vehicle" << endl;
        cout << "2. Update vehicle" << endl;
        cout << "3. Delete vehicle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1)
        {
            if (vehicleCount == 0) {
                cout << "No vehicles in the system!" << endl;
                continue;
            }
            
            cout << "Viewing all vehicle details..." << endl;
            for(int i = 0; i < vehicleCount; i++)
            {
                cout << "ID: " << id[i] << endl;
                cout << "Category: " << category[i] << endl;
                cout << "Seater Type: " << seaterType[i] << endl;
                cout << "Availability: " << (availability[i] ? "Available" : "Not Available") << endl;
                cout << "------------------------" << endl;
            }
        }
        else if (choice == 2)
        {
            if (vehicleCount == 0) {
                cout << "No vehicles in the system!" << endl;
                continue;
            }
            
            cout << "Updating vehicle" << endl;
            int updateId;
            cout << "Enter vehicle ID to update: ";
            cin >> updateId;
            
            bool found = false;
            for (int i = 0; i < vehicleCount; i++)
            {
                if(id[i] == updateId)
                {
                    cout << "Current details:" << endl;
                    cout << "Category: " << category[i] << endl;
                    cout << "Seater Type: " << seaterType[i] << endl;
                    cout << "Availability: " << (availability[i] ? "Available" : "Not Available") << endl;
                    
                    cout << "Enter new category: ";
                    cin.ignore();
                    getline(cin, category[i]);
                    cout << "Enter new seater type: ";
                    getline(cin, seaterType[i]);
                    cout << "Is it available? (1 for yes, 0 for no): ";
                    int tempAvail;
                    cin >> tempAvail;
                    availability[i] = (tempAvail != 0);
                    
                    cout << "Vehicle successfully updated!" << endl;
                    found = true;
                    break;
                }
            }
            
            if(!found)
            {
                cout << "ERROR: Vehicle ID " << updateId << " not found!" << endl;
                cout << "Available IDs: ";
                for(int i = 0; i < vehicleCount; i++) {
                    cout << id[i] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 3)
        {
            if (vehicleCount == 0) {
                cout << "No vehicles in the system!" << endl;
                continue;
            }
            
            cout << "Deleting vehicle" << endl;
            int deleteId;
            cout << "Enter Vehicle ID to delete: ";
            cin >> deleteId;
            
            bool found = false;
            for(int i = 0; i < vehicleCount; i++) 
            {
                if(id[i] == deleteId) 
                {
                    for(int j = i; j < vehicleCount - 1; j++) 
                    {
                        id[j] = id[j + 1];
                        category[j] = category[j + 1];
                        seaterType[j] = seaterType[j + 1];
                        availability[j] = availability[j + 1];
                    }
                    vehicleCount--;
                    cout << "Vehicle ID " << deleteId << " has been deleted!" << endl;
                    found = true;
                    break;
                }
            }
            
            if(!found) 
            {
                cout << "ERROR: Vehicle ID " << deleteId << " not found!" << endl;
                cout << "Available IDs: ";
                for(int i = 0; i < vehicleCount; i++) {
                    cout << id[i] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "Exiting vehicle management system..." << endl;
        }
        else 
        {
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    
    // Save data to file when exiting
    ofstream outfile("vehicles.txt");
    for (int i = 0; i < vehicleCount; i++)
    {
        outfile << id[i] << " " << category[i] << " " << seaterType[i] << " " << availability[i] << endl;
    }
    outfile.close();
    if (vehicleCount > 0) {
        cout << "Data saved to file successfully." << endl;
    }
    
    return 0;
}
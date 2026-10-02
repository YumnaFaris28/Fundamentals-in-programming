#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int choice;
    
    do {
        cout << "\n--- Sales Management ---" << endl;
        cout << "1. Execute Sales Report" << endl;
        cout << "2. View/Print Report" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        
        if (choice == 1)
        {
            string date;
            string vehicle;
            string territory;
            string customer;
            char addMore;
            
            ofstream outFile("sales.txt", ios::app); // Use append mode
            
            if (!outFile)
            {
                cout << "Error: Cannot open output file." << endl;
                continue;
            }
            
            do {
                cout << "\nEnter date: ";
                getline(cin, date);
                
                cout << "Enter vehicle type: ";
                getline(cin, vehicle);
                
                cout << "Enter territory: ";
                getline(cin, territory);
                
                cout << "Enter customer: ";
                getline(cin, customer);
                
                // Write to file
                outFile << "Date: " << date << endl;
                outFile << "Vehicle: " << vehicle << endl;
                outFile << "Territory: " << territory << endl;
                outFile << "Customer: " << customer << endl;
                outFile << "------------------------" << endl;
                
                cout << "Sales entry added successfully!" << endl;
                
                cout << "Add another sales entry? (y/n): ";
                cin >> addMore;
                cin.ignore();
                
            } while (addMore == 'y' || addMore == 'Y');
            
            outFile.close();
        }
        else if (choice == 2)
        {
            ifstream inFile("sales.txt");
            
            if (!inFile)
            {
                cout << "Error: No sales report found. Please generate a report first." << endl;
                continue;
            }
            
            cout << "\n--- Sales Report ---" << endl;
            string line;
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
            
            char printChoice;
            cout << "\nPrint this report? (y/n): ";
            cin >> printChoice;
            
            if (printChoice == 'y' || printChoice == 'Y')
            {
                cout << "Report printed successfully!" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting sales system..." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        
    } while (choice != 3);
    
    return 0;
}
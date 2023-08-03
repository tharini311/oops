#include <iostream>
#include <string>
using namespace std;
class Patient
{
protected:
    string name;
    int age;
    string address;
    string diagnosis;

public:
    void enterInfo()
    {
        cout << "Enter patient name: ";
        getline(cin, name);
        cout << "Enter patient age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter patient address: ";
        getline(cin, address);
        cout << "Enter diagnosis: ";
        getline(cin, diagnosis);
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Diagnosis: " << diagnosis << endl;
    }
};
class PediatricPatient : public Patient
{
private:
    string guardianName;

public:
    void enterInfo()
    {
        Patient::enterInfo();
        cout << "Enter guardian's name: ";
        getline(cin, guardianName);
    }
    void displayInfo()
    {
        Patient::displayInfo();
        cout << "Guardian's Name: " << guardianName << endl;
    }
};
int main()
{
    const int MAX_PATIENTS = 100;
    Patient *patients[MAX_PATIENTS];
    int numPatients = 0;
    char choice;
    do
    {
        cout << "1. Add a patient" << endl;
        cout << "2. Display all patients" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case '1':
        {
            char patientType;
            cout << "Enter patient type (P for pediatric, A for adult): ";
            cin >> patientType;
            cin.ignore();
            if (patientType == 'P')
            {
                PediatricPatient *pedPatient = new PediatricPatient();
                pedPatient->enterInfo();
                patients[numPatients] = pedPatient;
                numPatients++;
            }
            else if (patientType == 'A')
            {
                Patient *patient = new Patient();
                patient->enterInfo();
                patients[numPatients] = patient;
                numPatients++;
            }
            else
            {
                cout << "Invalid patient type." << endl;
            }
            break;
        }
        case '2':
            if (numPatients == 0)
            {
                cout << "No patients in the database." << endl;
            }
            else
            {
                for (int i = 0; i < numPatients; i++)
                {
                    cout << "Patient " << (i + 1) << ":" << endl;
                    patients[i]->displayInfo();
                    cout << endl;
                }
            }
            break;
        case '0':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != '0');
    return 0;
}

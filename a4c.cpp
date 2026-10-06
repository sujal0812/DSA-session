#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    string priority;
    int priorityLevel;
};

class EmergencyRoom {
private:
    Patient patients[100];
    int size;
    int nextId;

    int getPriorityLevel(string priority) {
        if (priority == "Critical" || priority == "critical")
            return 3;
        else if (priority == "Serious" || priority == "serious")
            return 2;
        else
            return 1;
    }

public:
    EmergencyRoom() {
        size = 0;
        nextId = 1;
    }

    // Register a patient
    void registerPatient() {
        if (size == 100) {
            cout << "\nQueue is full!\n";
            return;
        }

        Patient p;

        p.id = nextId++;

        cout << "\nEnter patient name: ";
        cin.ignore();
        getline(cin, p.name);

        cout << "Enter priority (Critical / Serious / Normal): ";
        cin >> p.priority;

        p.priorityLevel = getPriorityLevel(p.priority);

        if (p.priorityLevel == 3)
            p.priority = "Critical";
        else if (p.priorityLevel == 2)
            p.priority = "Serious";
        else
            p.priority = "Normal";

        patients[size] = p;
        size++;

        cout << "\nPatient registered successfully!";
        cout << "\nPatient ID: " << p.id << endl;
    }

    // Display patients according to priority
    void displayQueue() {
        if (size == 0) {
            cout << "\nNo patients waiting.\n";
            return;
        }

        cout << "\nWAITING QUEUE \n";

        // Display in priority order without changing the actual array
        bool served[100] = {false};

        for (int count = 0; count < size; count++) {
            int highest = -1;

            for (int i = 0; i < size; i++) {
                if (!served[i]) {
                    if (highest == -1 ||
                        patients[i].priorityLevel > patients[highest].priorityLevel) {
                        highest = i;
                    }
                }
            }

            cout << "ID: " << patients[highest].id
                 << " | Name: " << patients[highest].name
                 << " | Priority: " << patients[highest].priority << endl;

            served[highest] = true;
        }

    }

    // Serve highest-priority patient
    void servePatient() {
        if (size == 0) {
            cout << "\nNo patients waiting.\n";
            return;
        }

        int highest = 0;

        // Find highest-priority patient
        for (int i = 1; i < size; i++) {
            if (patients[i].priorityLevel > patients[highest].priorityLevel) {
                highest = i;
            }
        }

        Patient p = patients[highest];

        cout << "\n PATIENT SERVED\n";
        cout << "Patient ID : " << p.id << endl;
        cout << "Name       : " << p.name << endl;
        cout << "Priority   : " << p.priority << endl;

        // Remove patient by shifting remaining patients
        for (int i = highest; i < size - 1; i++) {
            patients[i] = patients[i + 1];
        }

        size--;
    }
};

int main() {
    EmergencyRoom er;
    int choice;

    do {
        cout << "\n HOSPITAL EMERGENCY ROOM";
        cout << "\n1. Register Patient";
        cout << "\n2. Display Waiting Queue";
        cout << "\n3. Serve Patient";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                er.registerPatient();
                break;

            case 2:
                er.displayQueue();
                break;

            case 3:
                er.servePatient();
                break;

            case 4:
                cout << "\nThank you!\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

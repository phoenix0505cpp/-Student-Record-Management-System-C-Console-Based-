#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

vector<Student> students;

// Add a new student
void addStudent() {
    Student s;
    cout << "\nEnter Roll Number: ";
    cin >> s.roll;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    cout << "Student added successfully!\n";
}

// Display all students
void displayStudents() {
    if (students.empty()) {
        cout << "\nNo records available.\n";
        return;
    }

    cout << "\nStudent Records:\n";
    for (auto &s : students) {
        cout << "Roll: " << s.roll
             << ", Name: " << s.name
             << ", Marks: " << s.marks << endl;
    }
}

// Search student by roll number
void searchStudent() {
    int roll;
    cout << "\nEnter roll number to search: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.roll == roll) {
            cout << "Record Found!\n";
            cout << "Name: " << s.name << ", Marks: " << s.marks << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

// Update student details
void updateStudent() {
    int roll;
    cout << "\nEnter roll number to update: ";
    cin >> roll;
    cin.ignore();

    for (auto &s : students) {
        if (s.roll == roll) {
            cout << "Enter new name: ";
            getline(cin, s.name);

            cout << "Enter new marks: ";
            cin >> s.marks;

            cout << "Record updated successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Delete student record
void deleteStudent() {
    int roll;
    cout << "\nEnter roll number to delete: ";
    cin >> roll;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "Record deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
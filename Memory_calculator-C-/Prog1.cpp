#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class MemoryCalculate {
    T id;
    string name;

public:
    MemoryCalculate(T id, string name) {
        this->id = id;
        this->name = name;
    }

    T getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};

vector<MemoryCalculate<int>> students;

void addStudent(int id, const string& name) {
    MemoryCalculate<int> newStudent(id, name);
    students.push_back(newStudent);
    cout << "Student added successfully.\n";
}

void displayAllStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\nList of Students:\n";
    for (const auto& student : students) {
        student.display();
    }
    cout << endl;
}

void searchStudentById(int id) {
    for (const auto& student : students) {
        if (student.getId() == id) {
            cout << "Student found:\n";
            student.display();
            return;
        }
    }
    cout << "No student with ID " << id << " found.\n";
}

void removeStudentById(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it);
            cout << "Student with ID " << id << " removed.\n";
            return;
        }
    }
    cout << "No student with ID " << id << " found.\n";
}

int main() {
    int choice;

    do {
        cout << "\nStudent Management Menu\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Remove Student by ID\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;

        int id;
        string name;

        switch (choice) {
            case 1:
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter student name: ";
                getline(cin, name);
                addStudent(id, name);
                break;

            case 2:
                displayAllStudents();
                break;

            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                searchStudentById(id);
                break;

            case 4:
                cout << "Enter ID to remove: ";
                cin >> id;
                removeStudentById(id);
                break;

            case 5:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Please choose between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}

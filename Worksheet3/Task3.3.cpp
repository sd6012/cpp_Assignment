#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int rollNo;
    char name[50];
    double marks;

    void inputData() {
        cout << "\nEnter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Marks (0-100): ";
        cin >> marks;
    }

    void displayData() {
        cout << "\n----------------------------------------" << "\n";
        cout << "Roll No: " << rollNo << "\n";
        cout << "Name: " << name << "\n";
        cout << "Marks: " << marks << "\n";
        cout << "----------------------------------------" << "\n";
    }
};

void checkMarks(double m) {
    if (m < 0 || m > 100) {
        throw "Marks should be between 0 and 100.";
    }
}

void readFile(Student students[], int& count, string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "\nError: Unable to open file.\n";
        return;
    }

    while (file >> students[count].rollNo >> students[count].name >> students[count].marks) {
        count++;
    }

    file.close();
}

void saveFile(Student students[], int count, string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "\nError: Unable to open file.\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        file << students[i].rollNo << " " << students[i].name << " " << students[i].marks << endl;
    }

    file.close();
}

void addStudent(Student students[], int& count) {
    Student newStudent;
    newStudent.inputData();

    try {
        checkMarks(newStudent.marks);
        students[count] = newStudent;
        count++;
        cout << "\nStudent record added successfully!\n";
    } catch (char* e) {
        cout << "\n" << e << "\n";
    }
}

void showMenu() {
    cout << "\n*********************************************";
    cout << "\n                 Main Menu";
    cout << "\n*********************************************";
    cout << "\n1) Add Student Record";
    cout << "\n2) Save and Exit";
    cout << "\n3) Show Student Records";
    cout << "\n=============================================";
    cout << "\nEnter your choice: ";
}

void showRecords(Student students[], int count) {
    if (count == 0) {
        cout << "\nNo student records to display.\n";
        return;
    }
    cout << "\n*********************************************";
    cout << "\n              Saved Student Records";
    cout << "\n*********************************************";
    for (int i = 0; i < count; ++i) {
        students[i].displayData();
    }
    cout << "=============================================\n";
}

void menu() {
    Student students[100];
    int count = 0;
    string filename = "students.txt";

    readFile(students, count, filename);

    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            addStudent(students, count);
        } else if (choice == 2) {
            saveFile(students, count, filename);
            cout << "\nRecords saved successfully.\n";
            showRecords(students, count);
            cout << "\nExiting program...\n";
            break;
        } else if (choice == 3) {
            showRecords(students, count);
        } else {
            cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}

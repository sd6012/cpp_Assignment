#include <iostream>
using namespace std;

class Student {
public:
    string studentName;
    int m1, m2, m3;
    int totalMarks;
    char grade;
    float average;

    void getInfo() {
        cout << "Enter student name: ";
        cin >> studentName;

        cout << "Marks of first subject: ";
        cin >> m1;

        cout << "Marks of second subject: ";
        cin >> m2;

        cout << "Marks of third subject: ";
        cin >> m3;


        if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100) {
                cout << " ";
            cout << "\nInvalid Input! Marks must be between 0 and 100" << endl;
        }
    }

    void calculateTotal() {
        totalMarks = m1 + m2 + m3;
    }

    void calculateGrade() {
        average = totalMarks / 3.0;

        if (average >= 90) {
            grade = 'A';
        } else if (average >= 80) {
            grade = 'B';
        } else if (average >= 70) {
            grade = 'C';
        } else if (average >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }

    void displayResults() {
        if (m1 >= 0 && m1 <= 100 && m2 >= 0 && m2 <= 100 && m3 >= 0 && m3 <= 100) {
            calculateTotal();
            calculateGrade();

            cout << "\nStudent Name: " << studentName << endl;
            cout << "\nTotal Marks: " << totalMarks << endl;
            cout << "\nAverage Marks: " << average << endl;
            cout << "\nGrade: " << grade << endl;
        } else {
            cout << "\nError: Unable to display the results." << endl;
        }
    }
};

int main() {
    Student student;
    student.getInfo();
    student.displayResults();

    return 0;
}

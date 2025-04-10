#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    bool validateMarks() {
        return marks >= 0 && marks <= 100;
    }
};

class StudentManager {
public:
    void read(string filename, vector<Student>& students) {
        ifstream infile(filename);
        if (infile.fail()) {
            cout << "\nError opening file for reading\n";
            return;
        }

        students.clear();

        Student s;
        while (infile >> s.roll) {
            infile.ignore();
            getline(infile, s.name, ' ');
            infile >> s.marks;
            students.push_back(s);
        }
        infile.close();
    }

    void write(vector<Student>& students) {
        Student s;
        cout << "\nEnter student roll number: ";
        cin >> s.roll;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, s.name);
        cout << "Enter student marks: ";
        cin >> s.marks;

        if (!s.validateMarks()) {
            cout << "Marks must be between 0 and 100\n";
            return;
        }
        students.push_back(s);
        cout << "Student record added successfully!\n";
    }

    void save(string filename, vector<Student>& students) {
        ofstream outfile(filename);
        if (outfile.fail()) {
            cout << "Error opening file for writing\n";
            return;
        }

        for (auto& s : students) {
            outfile << s.roll << " " << s.name << " " << s.marks << "\n";
        }
        outfile.close();
        cout << "Records saved to file successfully!\n";
    }

    void displayRecords(vector<Student>& students) {
        if (students.empty()) {
            cout << "\nNo student records available.\n";
            return;
        }

        cout << "\n|===============================================|";
        cout << "\n|             Student Records                   |";
        cout << "\n|===============================================|";
        for (auto& s : students) {
            cout << "\nRoll No: " << s.roll << " | Name: " << s.name << " | Marks: " << s.marks;
        }
        cout << "\n|===============================================|\n";
    }
};

class BookManager {
public:
    void writeBooks(string filename, string titles[], int count) {
        ofstream outfile(filename, ios::binary);
        if (outfile.fail()) {
            cout << "Error opening file for writing\n";
            return;
        }

        for (int i = 0; i < count; ++i) {
            outfile.write(titles[i].c_str(), titles[i].length() + 1);
        }
        outfile.close();
    }

    bool readBook(string filename, string title) {
        ifstream infile(filename, ios::binary);
        if (infile.fail()) {
            cout << "Error opening file for reading\n";
            return false;
        }

        string storedtitle;
        while (getline(infile, storedtitle, '\0')) {
            if (storedtitle == title) {
                return true;
            }
        }
        return false;
    }
};

void showMenu() {
    cout << "\n\n***********************************************";
    cout << "\n                Main Menu";
    cout << "\n***********************************************";
    cout << "\n1) Add New Student Record";
    cout << "\n2) Save and Exit";
    cout << "\n3) Show Student Records";
    cout << "\n4) Add New Book Titles";
    cout << "\n5) Search for a Book";
    cout << "\n***********************************************";
    cout << "\nPlease enter your choice: ";
}

int main() {
    vector<Student> students;
    string studentfile = "students.txt";

    StudentManager studentManager;
    studentManager.read(studentfile, students);

    int choice;
    BookManager bookManager;
    string bookfile = "books.dat";
    int bookcount = 10;
    string books[bookcount];

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                studentManager.write(students);
                break;
            case 2:
                studentManager.save(studentfile, students);
                cout << "Records saved to file!\n";
                break;
            case 3:
                studentManager.displayRecords(students);
                break;
            case 4:
                cout << "\n|==============================================|";
                cout << "\n|            Enter 10 Book Titles              |";
                cout << "\n|==============================================|";
                for (int i = 0; i < bookcount; ++i) {
                    cout << "\nBook " << i + 1 << ": ";
                    getline(cin, books[i]);
                }
                bookManager.writeBooks(bookfile, books, bookcount);
                cout << "Books written to binary file successfully.\n";
                break;
            case 5: {
                string searchtitle;
                char searchagain = 'y';
                while (searchagain == 'y') {
                    cout << "\nEnter a book title to search: ";
                    getline(cin, searchtitle);

                    if (bookManager.readBook(bookfile, searchtitle)) {
                        cout << "The book is in the file.\n";
                    } else {
                        cout << "The book is not in the file.\n";
                    }

                    cout << "Do you want to search for another book? (y/n): ";
                    cin >> searchagain;
                    cin.ignore();
                }
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 2);

    cout << "\nThank you for using the system!\n";
    return 0;
}

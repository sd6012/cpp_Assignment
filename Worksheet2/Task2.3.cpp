#include <iostream>
using namespace std;

class MaxFinder {
public:
    int findMax(int a, int b) {
        return (a > b) ? a : b;
    }

    float findMax(float a, float b) {
        return (a > b) ? a : b;
    }

    int findMax(int a, int b, int c) {
        return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    }

    float findMax(int a, float b) {
        return (a > b) ? a : b;
    }
};

void menu() {
    MaxFinder m1;
    int choice;

    do {
        cout << "\nMenu:";
        cout << "\n1. Find max between two integers";
        cout << "\n2. Find max between two floating-point numbers";
        cout << "\n3. Find max among three integers";
        cout << "\n4. Find max between an integer and a float";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                cout << "Maximum: " << m1.findMax(a, b) << endl;
                break;
            }
            case 2: {
                float a, b;
                cout << "Enter two floating-point numbers: ";
                cin >> a >> b;
                cout << "Maximum: " << m1.findMax(a, b) << endl;
                break;
            }
            case 3: {
                int a, b, c;
                cout << "Enter three integers: ";
                cin >> a >> b >> c;
                cout << "Maximum: " << m1.findMax(a, b, c) << endl;
                break;
            }
            case 4: {
                int a;
                float b;
                cout << "Enter an integer and a float: ";
                cin >> a >> b;
                cout << "Maximum: " << m1.findMax(a, b) << endl;
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}

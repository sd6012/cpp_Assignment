#include <iostream>
using namespace std;

int main() {
    float c, f, temp;
    int choice;

    cout << "-----------------------------" << endl;
    cout << "| Choose the conversion type:|" << endl;
    cout << "-----------------------------" << endl;
    cout << "| 1. Celsius to Fahrenheit   |" << endl;
    cout << "| 2. Fahrenheit to Celsius   |" << endl;
    cout << "-----------------------------" << endl;
    cout << "Enter your choice (1 or 2):" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the temperature in Celsius:" << endl;
        cin >> temp;
        f = (temp * 9.0 / 5.0) + 32;
        cout << temp << " Celsius is " << f << " Fahrenheit." << endl;
    }
    else if (choice == 2) {
        cout << "Enter the temperature in Fahrenheit:" << endl;
        cin >> temp;
        c = (temp - 32) * 5.0 / 9.0;
        cout << temp << " Fahrenheit is " << c << " Celsius." << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

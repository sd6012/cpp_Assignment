#include <iostream>
using namespace std;

int main() {
    int a;
    char choice;

    do {
        cout << "\nEnter a positive number: " << endl;
        cin >> a;

        int n = a;

        if (a < 10) {
            cout << " " << endl;
            cout << "Single digit numbers are never bouncy." << endl;
        }
        else {
            bool increase = false, decrease = false;
            int lastDigit = a % 10;
            a /= 10;

            while (a > 0) {
                int currentDigit = a % 10;
                if (currentDigit < lastDigit) {
                    decrease = true;
                }
                else if (currentDigit > lastDigit) {
                    increase = true;
                }
                lastDigit = currentDigit;
                a /= 10;
            }

            if (increase && decrease) {
                cout << " " << endl;
                cout << n << " is a bouncy number." << endl;
            }
            else {
                cout << " " << endl;
                cout << n << " is not a bouncy number." << endl;
            }
        }

        cout << " " << endl;
        cout << "Do you want to check another number? (y/n): " << endl;
        cin >> choice;

    } while (choice == 'y');

    cout << " " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "+  Thank you for using the bouncy number checker!!!   +" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    return 0;
}

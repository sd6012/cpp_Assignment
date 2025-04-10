#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int lvl, num, guess, attempt = 5;
    int correct = 0;


    srand(time(0));

    cout << "====================================" << endl;
    cout << "  * Welcome to the Guessing Game *  " << endl;
    cout << "                                    " << endl;
    cout << "              Enjoy!!!              " << endl;
    cout << "====================================" << endl;

    cout << " Choose your Difficulty Level " << endl;


    cout << " 1. Easy " << endl;
    cout << " 2. Medium " << endl;
    cout << " 3. Hard " << endl;
    cout << " Enter your choice: " << endl;
    cin >> lvl;

    if (lvl == 1) {
        num = rand() % 8 + 1;
        cout << "\nYou chose Easy!" << endl;
        cout << "\nThe number is between 1 and 8." << endl;
    } else if (lvl == 2) {
        num = rand() % 30 + 1;
        cout << "\nYou chose Medium!" << endl;
        cout << "\nThe number is between 1 and 30." << endl;
    } else if (lvl == 3) {
        num = rand() % 50 + 1;
        cout << "\nYou chose Hard!" << endl;
        cout << "\nThe number is between 1 and 50." << endl;
    } else {
        cout << "Invalid Choice!" << endl;
        return 0;
    }

    cout << "-------------------------------------------" << endl;
    cout << "     Let's start the guessing game!        " << endl;
    cout << "-------------------------------------------" << endl;
    cout << "    Try to guess the number!    " << endl;

    while (correct == 0 && attempt > 0) {
        cout << "\nYou have " << attempt << " attempts left." << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < num) {
            cout << "Your guess is too low! Try again." << endl;
        } else if (guess > num) {
            cout << "Your guess is too high! Try again." << endl;
        } else {
            cout << "*****************************************" << endl;
            cout << "**   Congratulations! You guessed it!  **" << endl;
            cout << "**                                     **" << endl;
            cout << "**   The correct number is " << num << "!          **" << endl;
            cout << "*****************************************" << endl;
            correct = 1;
        }
        attempt--;
    }

    if (correct == 0) {
        cout << "*******************************************" << endl;
        cout << "**          Sorry! Attempts are Over     **" << endl;
        cout << "**                                       **" << endl;
        cout << "**      The correct number was " << num << "        **." << endl;
        cout << "*******************************************" << endl;
    }

    cout << "===============================================" << endl;
    cout << "      Thank you for playing the game!          " << endl;
    cout << "===============================================" << endl;

    return 0;
}

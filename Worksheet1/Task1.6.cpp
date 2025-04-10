#include <iostream>
using namespace std;

int main()
{
   char seat[5][5] = { {'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O'} };

                            int row, col;
                            char choice;

                            do {
                                cout << "    Cinema Screen   " << endl;
                                cout << "--------------------" << endl;
                                for (int i = 0; i < 5; i++) {
                                    for (int j = 0; j < 5; j++){
                                        cout << seat[i][j] << " ";
                                    }
                                    cout << endl;
                                }
                                cout << "---------------------" << endl;

                                cout << "Enter a row to book a seat: ";
                                cin >> row;
                                cout << "Enter a column to book a seat: ";
                                cin >> col;

                                if (row < 1 || row > 5 || col < 1 || col > 5){
                                    cout << " " << endl;
                                    cout << "Invalid row or column. Please enter values between 1 and 5." << endl;
                                }
                                else if (seat[row - 1][col - 1] == 'X') {
                                    cout << " " << endl;
                                    cout << "Sorry! This seat is already booked." << endl;
                                }
                                else {
                                    seat[row - 1][col - 1] = 'X';
                                    cout << " " << endl;
                                    cout << "Seat successfully booked!" << endl;
                                }
                                cout << " " << endl;
                                cout << "Updated seating arrangement: " << endl;

        cout << "Cinema Screen" << endl;
        cout << "---------------------" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << seat[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----------------------------" << endl;

        cout << " " << endl;
        cout << "Do you want to book another seat? (y/n): ";
        cin >> choice;




                             } while (choice == 'y');
                          cout << " " << endl;
                          cout << "Thank you for booking!" << endl;
                          return 0;
}

#include <iostream>
using namespace std;

int main() {
int day;

while (true){
cout << "  \nEnter the number between 1 to 7:  " << endl;
cout << "====================================" << endl;
cin >> day;

if (day == 0)
{
    cout << "====================================" << endl;
    cout << "          Exiting the program"        << endl;
    break;
}

switch(day){
        case 1:
            cout << "* Sunday *" << endl;
            break;
        case 2:
            cout << "* Monday *" << endl;
            break;
        case 3:
            cout << "* Tuesday *" << endl;
            break;
        case 4:
            cout << "* Wednesday *" << endl;
            break;
        case 5:
            cout << "* Thursday *" << endl;
            break;
        case 6:
            cout << "* Friday *" << endl;
            break;
        case 7:
            cout << "* Saturday *" << endl;
            break;
        default:
            cout << "Invalid number! Please enter the correct number" << endl;
}

}

return 0;

}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void displayMenu() {
    cout << "\n=*************************************\n";
    cout << "      AGE RECORD MANAGEMENT SYSTEM      \n";
    cout << "****************************************\n";
    cout << "1. Add name-age pair\n";
    cout << "2. Find people above a certain age\n";
    cout << "3. Display names alphabetically\n";
    cout << "4. Exit\n";
    cout << "=====================================\n";
}

void add(map<string, int>& ageMap, vector<string>& nameList) {
    string name;
    int age;
    cout << "\n--- Add Name-Age Pair ---\n";
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    nameList.push_back(name);
    ageMap[name] = age;
    cout << "\nEntry added successfully!\n";
}

void findAboveAge(const map<string, int>& ageMap, int ageLimit) {
    bool found = false;
    cout << "\n--- People above " << ageLimit << " years ---\n";
    for (const auto& person : ageMap) {
        if (person.second > ageLimit) {
            cout << person.first << " (Age: " << person.second << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No people found above this age limit.\n";
    }
}

void showNames(const vector<string>& nameList) {
    cout << "\n--- Sorted Name List ---\n";
    if (nameList.empty()) {
        cout << "No names have been added yet.\n";
        return;
    }

    vector<string> sortedNames = nameList;
    sort(sortedNames.begin(), sortedNames.end());

    for (const auto& name : sortedNames) {
        cout << name << endl;
    }
}

int main() {
    map<string, int> ageMap;
    vector<string> nameList;
    int choice, ageLimit;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add(ageMap, nameList);
                break;
            case 2:
                cout << "Enter the age limit: ";
                cin >> ageLimit;
                findAboveAge(ageMap, ageLimit);
                break;
            case 3:
                showNames(nameList);
                break;
            case 4:
                cout << "\nExiting program. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

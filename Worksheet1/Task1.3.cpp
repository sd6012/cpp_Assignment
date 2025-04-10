#include <iostream>
using namespace std;

int main() {
int a;
cout << "Enter the numbers of elements: "<< endl;
cin >> a;

int arr[a];

cout << "\nEnter " << a << " numbers: " << endl;
for (int i = 0; i < a; i++){
    cin >> arr[i];
}
for (int i = 0; i < a - 1; i++){
for (int j = 0; j < a - 1 - i; j++){
   if (arr[j] > arr[j+1]) {
    int temp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = temp;
    }
  }
}
cout << "\nThe sorted array in ascending order is:" << endl;
for (int i = 0; i < a; i ++ ){
    cout << arr[i] << " ";
}
cout << endl;
return 0;
}

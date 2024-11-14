#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter the number of elements in the array: ";
    cin >> num;

    int arr[num];

 
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < num; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }

  
    int product = 1; 
    for(int i = 0; i < num; i++) {
        product *= arr[i];  
    }

   
    cout << "The product of all elements is: " << product << endl;

    return 0;
}

#include<iostream>
using namespace std;

int main() {
    int rows, col;

    cout << "enter rows: ";
    cin >> rows;
    cout << "enter columns: ";
    cin >> col;
    int arry[rows][col];
    cout << "enter the elements\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            cout << "elements[" << i << "][" << j << "]: ";
            cin >> arry[i][j];
        }
    }
    cout << "The 2D array is:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            cout << arry[i][j] << " ";
        }
        cout << endl;
    }
    int sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            sum += arry[i][j];
        }
    }
    cout << "The sum is: " << sum << endl;
      return 0;
}

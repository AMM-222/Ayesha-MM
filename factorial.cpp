#include <iostream>
using namespace std;
int main() {
    int n;                  
    long factorial = 1;  
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0) {
        cout << "INVALID.";
    } else {
        int i = 1;  
        do {
            factorial *= i; 
            i++;             
        } 
		while (i <= n);    

        cout << "Factorial of " << n << " is " << factorial << endl;  
    }

    return 0;
}

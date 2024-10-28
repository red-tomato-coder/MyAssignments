#include <iostream>
#include <algorithm>
#include <limits>
#include "Sorting.h"
#include "Comb.h"  

using namespace std;

void clearInput() {
    cin.clear();  // Clear input flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
}
int* createArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Type " << i << "'th element: ";
        cin >> arr[i];
    }
    return arr;
}
void handlePart1() {
    int n, k;
    cout << "Enter n & k: ";
    cin >> n >> k;
    cout << "Factorial: " << FACTORIAL(n) << "\n";
    cout << "A: " << A(n, k) << "\n";
    cout << "A with repetitions: " << An(n, k) << "\n";
    cout << "C: " << C(n, k) << "\n";
    cout << "C with repetitions: " << Cn(n, k) << "\n";
}

void handlePart2() {
    int n;
    cout << "Size of array: ";
    cin >> n;
    int* A = createArray(n);
    GenPerm(A, n);          
    delete[] A;            
}

void handlePart3() {
    int n, k;
    cout << "Size of array: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;
    int* A = createArray(n);
    GenComb(A, n, k);
    delete[] A;
}

// Main menu function
void SCREENSTARTER() {
    int p;
    while (true) {  // Loop to keep showing the menu
        cout << "\nChoose a PART (1, 2, 3) or 0 to exit: ";
        cin >> p;

        if (cin.fail() || p < 0 || p > 3) {
            cout << "Invalid option. Please try again.\n";
            clearInput();
            continue;
        }

        switch (p) {
            case 0:
                cout << "Exiting program.\n";
                return;
            case 1:
                handlePart1();
                break;
            case 2:
                handlePart2();
                break;
            case 3:
                handlePart3();
                break;
        }
    }
}

// Main function
int main() {
    SCREENSTARTER();  // Start the menu
    return 0;
}


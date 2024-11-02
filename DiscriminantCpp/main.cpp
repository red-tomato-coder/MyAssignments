#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cout << "Type a, b, and c: ";
    cin >> a >> b >> c;

    int D = pow(b, 2) - 4 * a * c;

    if (D < 0) {
        cout << "Discriminant is less than 0. No roots." << endl;
    }
    else if (D == 0) {
        cout << "Discriminant is 0, one root found: " << -b / (2.0 * a) << endl;
    }
    else {
        cout << "Two roots are found\n"
             << "x1 = " << (-b - sqrt(D)) / (2.0 * a) << endl
             << "x2 = " << (-b + sqrt(D)) / (2.0 * a) << endl;
    }

    return 0;
}


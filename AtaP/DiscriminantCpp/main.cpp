#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cout << "Type a, b, and c: ";
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "Infinite solutions exist (0 = 0)." << endl;
        return 0;
    }

    if (a == 0 && b == 0) {
        cout << "No solution exists (contradiction: 0 = " << c << ")." << endl;
        return 0;
    }

    if (a == 0) {
        cout << "Linear equation, single root: x = " << -c / b << endl;
        return 0;
    }

    double D = pow(b, 2) - 4 * a * c;

    if (D > 0) {

        double x1 = (-b - sqrt(D)) / (2 * a);
        double x2 = (-b + sqrt(D)) / (2 * a);
        cout << "Two real roots found:\n"
             << "x1 = " << x1 << endl
             << "x2 = " << x2 << endl;
    } else if (D == 0) {

        double x = -b / (2 * a);
        cout << "Discriminant is 0, one real root found: x = " << x << endl;
    } else {

        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-D) / (2 * a);
        cout << "Discriminant is less than 0, two complex roots found:\n"
             << "x1 = " << realPart << " - " << imaginaryPart << "i" << endl
             << "x2 = " << realPart << " + " << imaginaryPart << "i" << endl;
    }

    return 0;
}


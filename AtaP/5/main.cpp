#include <iostream>
using namespace std;

enum Day {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

const char* dayToString(Day d) {
    switch(d) {
        case Monday: return "Monday";
        case Tuesday: return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday: return "Thursday";
        case Friday: return "Friday";
        case Saturday: return "Saturday";
        case Sunday: return "Sunday";
        default: return "Unknown";
    }
}

int main() {
    Day today = Wednesday;
    cout << "Сьогодні: " << dayToString(today) << endl;
    return 0;
}


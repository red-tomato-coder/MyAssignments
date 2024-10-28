#include "LogCon.h"
#include <iostream>

using namespace std;

// Functions f1 to f25
bool f1(bool a, bool b, bool c){
    return XOR(EQU(OR(c, a), IMP(a, b)), OR(a, b));
}
bool f2(bool a, bool b, bool c){
    return EQU(IMP(a, AND(b, c)), AND(IMP(a, b), IMP(a, c)));
}
bool f3(bool a, bool b, bool c){
    return IMP(AND(AND(a, c), b), OR(IMP(b, c), a));
}
bool f4(bool a, bool b, bool c) {
    return XOR(AND(OR(a, b), a), AND(c, b));
}
bool f5(bool a, bool b, bool c) {
    return EQU(OR(AND(a, b), c), AND(c, a));
}
bool f6(bool a, bool b, bool c) {
    return XOR(OR(AND(a, b), c), OR(OR(a, b), c));
}
bool f7(bool a, bool b, bool c) {
    return EQU(AND(OR(a, b), c), OR(b, c));
}
bool f8(bool a, bool b, bool c) {
    return XOR(EQU(OR(a, OR(c, a)), AND(b, a)), OR(b, c));
}
bool f9(bool a, bool b, bool c) {
    return EQU(AND(AND(a, b), c), OR(IMP(a, b), c));
}
bool f10(bool a, bool b, bool c) {
    return EQU(IMP(AND(b, c), OR(a, c)), IMP(AND(b, c), AND(c, a)));
}
bool f11(bool a, bool b, bool c) {
    return IMP(AND(IMP(a, b), c), XOR(a, b));
}
bool f12(bool a, bool b, bool c) {
    return EQU(IMP(b, AND(a, c)), AND(IMP(b, a), IMP(b, c)));
}
bool f13(bool a, bool b, bool c) {
    return IMP(OR(IMP(a, b), c), OR(a, b));
}
bool f14(bool a, bool b, bool c) {
    return IMP(AND(IMP(a, b), c), XOR(a, c));
}
bool f15(bool a, bool b, bool c) {
    return IMP(AND(IMP(a, b), OR(c, a)), OR(a, b));
}
bool f16(bool a, bool b, bool c) {
    return XOR(AND(IMP(a, b), c), OR(IMP(a, b), c));
}
bool f17(bool a, bool b, bool c) {
    return EQU(OR(AND(a, b), c), IMP(a, b));
}
bool f18(bool a, bool b, bool c) {
    return IMP(AND(XOR(a, b), IMP(b, c)), IMP(c, a));
}
bool f19(bool a, bool b, bool c) {
    return IMP(AND(a, OR(b, c)), XOR(AND(a, b), AND(b, c)));
}
bool f20(bool a, bool b, bool c) {
    return IMP(OR(AND(a, c), b), OR(b, c));
}
bool f21(bool a, bool b, bool c) {
    return EQU(OR(AND(a, b), c), IMP(c, b));
}
bool f22(bool a, bool b, bool c) {
    return IMP(IMP(a, b), IMP(AND(a, b), c));
}
bool f23(bool a, bool b, bool c) {
    return XOR(OR(a, b), IMP(a, AND(b, c)));
}
bool f24(bool a, bool b, bool c) {
    return IMP(IMP(OR(a, c), b), OR(IMP(a, b), IMP(a, c)));
}
bool f25(bool a, bool b, bool c) {
    return EQU(XOR(a, AND(b, c)), AND(XOR(a, b), XOR(a, c)));
}

void printTables() {
    bool a, b, c;
    cout << "a\tb\tc\tf1\tf2\tf3\tf4\tf5\tf6\tf7\tf8\tf9\tf10\tf11\tf12\tf13\tf14\tf15\tf16\tf17\tf18\tf19\tf20\tf21\tf22\tf23\tf24\tf25\n";

    for (int i = 0; i < 2; i++) {
        a = i;
        for (int j = 0; j < 2; j++) {
            b = j;
            for (int k = 0; k < 2; k++) {
                c = k;
                cout << a << "\t" << b << "\t" << c << "\t"
                     << f1(a, b, c) << "\t" << f2(a, b, c) << "\t"
                     << f3(a, b, c) << "\t" << f4(a, b, c) << "\t"
                     << f5(a, b, c) << "\t" << f6(a, b, c) << "\t"
                     << f7(a, b, c) << "\t" << f8(a, b, c) << "\t"
                     << f9(a, b, c) << "\t" << f10(a, b, c) << "\t"
                     << f11(a, b, c) << "\t" << f12(a, b, c) << "\t"
                     << f13(a, b, c) << "\t" << f14(a, b, c) << "\t"
                     << f15(a, b, c) << "\t" << f16(a, b, c) << "\t"
                     << f17(a, b, c) << "\t" << f18(a, b, c) << "\t"
                     << f19(a, b, c) << "\t" << f20(a, b, c) << "\t"
                     << f21(a, b, c) << "\t" << f22(a, b, c) << "\t"
                     << f23(a, b, c) << "\t" << f24(a, b, c) << "\t"
                     << f25(a, b, c) << "\n";
            }
        }
    }
}

int main() {
    printTables();
    return 0;
}


#include "LogCon.h"


bool NOT(bool a) {
    return !a;
}

bool AND(bool a, bool b) {
    return a && b;
}

bool OR(bool a, bool b) {
    return a || b;
}

bool IMP(bool a, bool b) {
    return !a || b;
}

bool EQU(bool a, bool b) {
    return a == b;
}

bool XOR(bool a, bool b) {
    return a != b;
}

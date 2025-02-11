#include <iostream>
#include <algorithm>
#include <cmath>
#include "Sorting.h"  

using namespace std;

int FACTORIAL(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int A(int n, int k) { return FACTORIAL(n) / FACTORIAL(n - k); }
int An(int n, int k) { return pow(n, k); }
int C(int n, int k) { return FACTORIAL(n) / (FACTORIAL(k) * FACTORIAL(n - k)); }
int Cn(int n, int k) { return FACTORIAL(n + k - 1) / (FACTORIAL(k) * FACTORIAL(n - 1)); }

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Swap function

void swap(int* A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void permuteLex(int* A, int l, int n) {
    if (l == n) {
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = l; i < n; i++) {
        if (i == l || A[i] != A[l]) {  // Avoid duplicate swaps
            swap(A, l, i);
            permuteLex(A, l + 1, n);
            swap(A, l, i);  // Backtrack
        }
    }
}

void GenPerm(int* A, int n) {
    sort(A, A + n);  // Start with the smallest permutation
    permuteLex(A, 0, n);
}

void GenComb(int* A, int n, int k) {
    sort(A, A + n);

    int* N = new int[k];
    int* B = new int[k];

    for (int i = 0; i < k; i++) {
        N[i] = i;
        B[i] = A[i];
    }
    printArray(B, k);
    cout << endl;

    while (true) {
        int d = k - 1;
        while (d >= 0 && N[d] == n - k + d) {
            d--;
        }

        if (d < 0) break;

        N[d]++;
        for (int j = d + 1; j < k; j++) {
            N[j] = N[j - 1] + 1;
        }

        for (int i = 0; i < k; i++) {
            B[i] = A[N[i]];
        }

        printArray(B, k);
        cout << endl;
    }

    delete[] N;
    delete[] B;
}


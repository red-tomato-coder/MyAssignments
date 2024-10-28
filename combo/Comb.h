#ifndef COMB_H
#define COMB_H

int FACTORIAL(int n);
int A(int n, int k);
int An(int n, int k);
int C(int n, int k);
int Cn(int n, int k);
void GenPerm(int* A, int n);
void generatePermutations(int* A, int start, int end);
void swap(int* A, int i, int j);
void printArray(int* A, int size);
void sortArray(int* arr, int n);
void GenComb(int* A, int n, int k);

#endif


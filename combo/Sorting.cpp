#include "Sorting.h"
#include <iostream>

using namespace std;

void BUBBLE(int* arr, int l, int r) {
    for (int i = l; i < r - 1; i++) {
        for (int j = l; j < r - (i - l) - 1; j++) { // Corrected the index range here
            if (arr[j] > arr[j + 1]) {
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }

    // Print the entire array after sorting
    for (int k = 0; k < 10; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

void SELECTION(int* arr, int l, int r) {
    // Print the entire array before sorting
    for (int k = 0; k < 10; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    for (int i = l; i < r - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < r; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    // Print the entire array after sorting
    for (int k = 0; k < 10; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

void INSERTION(int* arr, int l, int r) {
    for (int i = l; i < r; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << endl;
}


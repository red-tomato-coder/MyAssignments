#include "Heap.h"
#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {4, 10, 3, 5, 1};
    std::cout << "Original array: ";
    printArray(arr);

    HeapSort(arr, true);
    std::cout << "Sorted array (ascending): ";
    printArray(arr);

    HeapSort(arr, false);
    std::cout << "Sorted array (descending): ";
    printArray(arr);

    return 0;
}


#ifndef HEAP_H
#define HEAP_H

#include <vector>

int Parent(int i);
int Left(int i);
int Right(int i);

void MaxHeapify(std::vector<int>& arr, int i, int heap_size);
void BuildMaxHeap(std::vector<int>& arr);
void MinHeapify(std::vector<int>& arr, int i, int heap_size);
void BuildMinHeap(std::vector<int>& arr);
void HeapSort(std::vector<int>& arr, bool ascending);

int HeapExtractMax(std::vector<int>& arr, int& heap_size);
void HeapIncreaseKey(std::vector<int>& arr, int i, int key);
void MaxHeapInsert(std::vector<int>& arr, int key, int& heap_size);

int HeapExtractMin(std::vector<int>& arr, int& heap_size);
void HeapDecreaseKey(std::vector<int>& arr, int i, int key);
void MinHeapInsert(std::vector<int>& arr, int key, int& heap_size);

#endif // HEAP_H


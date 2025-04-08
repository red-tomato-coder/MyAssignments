#ifndef HEAP_H
#define HEAP_H

#include <vector>

int Parent(int i);
int Left(int i);
int Right(int i);

void MaxHeapify(std::vector<int>& Array, int n, int i);
void MinHeapify(std::vector<int>& Array, int n, int i);

void BuildMaxHeap(std::vector<int>& Array);
void BuildMinHeap(std::vector<int>& Array);

void HeapSort(std::vector<int>& Array, bool Mode);

void Insert(std::vector<int>& Array, int key, bool Mode);

int Maximum(std::vector<int>& Array);
int Minimum(std::vector<int>& Array);

void HeapIncreaseKey(std::vector<int>& Array, int position, int key);
void HeapDecreaseKey(std::vector<int>& Array, int position, int key);

void ExtractMax(std::vector<int>&Array);
void ExtractMin(std::vector<int>&Array);

#endif // HEAP_H


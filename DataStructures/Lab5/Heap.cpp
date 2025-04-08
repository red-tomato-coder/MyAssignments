#include "Heap.h"
#include <iostream>
#include <vector>

int Parent(int i) { return (i - 1) / 2; }
int Left(int i) { return 2 * i + 1; }
int Right(int i) { return 2 * i + 2; }

void MaxHeapify(std::vector<int>& Array, int n, int i) {
    int largest = i;  
    int left = Left(i);  
    int right = Right(i);  

    if (left < n && Array[left] > Array[largest])
        largest = left;
    
    if (right < n && Array[right] > Array[largest])
        largest = right;

    if (largest != i) { 
        std::swap(Array[i], Array[largest]);
        MaxHeapify(Array, n, largest);
    }
}

void MinHeapify(std::vector<int>& Array, int n, int i) {
    int smallest = i;  
    int left = Left(i);  
    int right = Right(i);  

    if (left < n && Array[left] < Array[smallest])
        smallest = left;
    
    if (right < n && Array[right] < Array[smallest])
        smallest = right;

    if (smallest != i) {  
        std::swap(Array[i], Array[smallest]);
        MinHeapify(Array, n, smallest);
    }
}

void BuildMaxHeap(std::vector<int>& Array) {
    int n = Array.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(Array, n, i);
    }
}

void BuildMinHeap(std::vector<int>& Array) {
    int n = Array.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(Array, n, i);
    }
}

void HeapSort(std::vector<int>& Array, bool Mode) {
    int n = Array.size();

    if(Mode){

      BuildMaxHeap(Array);

      for (int i = n - 1; i > 0; i--) {
        std::swap(Array[0], Array[i]);
        MaxHeapify(Array, i, 0);
      }
    }
    else{
      BuildMinHeap(Array);

      for (int i = n-1; i > 0; i--) {
        std::swap(Array[0], Array[i]);
        MinHeapify(Array, i, 0);
      }
    }
}
/*

/============================================\
|                 ЧАСТИНА 2                  |
\============================================/

*/

void Insert(std::vector<int>& Array, int key, bool Mode){
  Array.push_back(key);
  if(Mode){
    HeapSort(Array, false);
  }
  else{
    HeapSort(Array, true);
  }
}

int Maximum(std::vector<int>& Array){
  return Array[0];
}

int Minimum(std::vector<int>& Array){
  return Array[0];
}

void HeapIncreaseKey(std::vector<int>& Array, int position, int key){
  if(Array[position] < key){   
    Array[position] = key;
    HeapSort(Array, false);
  }
  else{
    std::cout << "Зміни не прийняті";
  }

  return;
}

void HeapDecreaseKey(std::vector<int>& Array, int position, int key){
  if(Array[position]>key){   
    Array[position] = key;
    HeapSort(Array, true);
  }
  else{
    std::cout << "Зміни не прийняті";
  }

  return;
}

void ExtractMax(std::vector<int>& Array){
  Array.erase(Array.begin());
  HeapSort(Array, false);
}

void ExtractMin(std::vector<int>& Array){
  Array.erase(Array.begin());
  HeapSort(Array, true);
}

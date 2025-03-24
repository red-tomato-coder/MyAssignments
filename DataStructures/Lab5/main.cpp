#include <iostream>
#include <vector>
#include "Heap.h"

int main(){

  Node* root1 = nullptr;
  Node* root2 = nullptr;
  
  vector<int> unsorted1 = {7, 3, 4, 6, 1, 9, 5};
  vector<int> unsorted2 = {7, 3, 4, 6, 1, 9, 5};

 BuildMaxHeap(unsorted1, unsorted1.size(), root1); 
}

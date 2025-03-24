#include <iostream>
#include "Heap.h"

int Parent(int i) {
    return i / 2; }

int Left(int i) {
    return 2 * i;
}

int Right(int i) {
    return 2 * i + 1;
}

void BuildMaxHeap(vector<int> array, int i, Node* &root){
  if(root == nullptr)
    root -> key = array[0];
  int l = Left(i);
  int r = Right(i);
  root -> left = array[l];
  root -> right = array[r];
  BuildMaxHeap(array, l, root -> left);
  BuildMaxHeap(array, r, root -> right);
  return;
}

void MaxHeapify(Node* &root){
  while (root -> left != nullptr && root -> right != nullptr) {
    
  }
}

void BuildMinHeap(vector<int> array, Node* &root, int i){

}

void MinHeapify(){

}

void HeapSort(){

}

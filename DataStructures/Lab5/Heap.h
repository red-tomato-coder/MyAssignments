#ifdef HEAP_H
#define HEAP_H

struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;

    Node(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};



#endif // HEAP_H

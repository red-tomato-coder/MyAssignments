#ifndef TREES_H
#define TREES_H

struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;

    Node(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

Node* CreateTree(int key, int left, int right);
void CreateNode(Node* root, int ParentKey);
void PrintTree(Node* root);
Node* FindNode(Node* root, int ParentKey);
void InOrder(Node* root);
void PostOrder(Node* root);
void PreOrder(Node* root);
int TreeHeight(Node* root);
int treeHeight(Node* root);
void printSpaces(int count);

Node* CreateRootBST(int key, int first_key, int second_key);
void InsertNodeBST(Node* root, Node* parentNode, int ChildKey);
Node* SearchNodeBST(Node* root, int SearchedKey);
void DeleteNodeBST(Node*& root, Node* delNode);
Node* SuccessorNodeBST(Node* node);
Node* PredecessorNodeBST(Node* node);
void PrintTree(Node* root);
void Recursive(Node*& root, int i, int j);
void RecursiveBST(Node*& root, int i, int& j);

#endif // TREES_H

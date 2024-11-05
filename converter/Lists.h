#ifndef LISTS_H
#define LISTS_H

// Use 'int' or another type for datatype if unspecified
typedef int datatype;

struct Node {
    datatype key;
    Node* next;
    Node* previous; // Only relevant for doubly linked lists
};

// Function prototypes
void push(Node*& head, datatype key);
void pop(Node*& head);
void show(Node* head);
void show2(Node* head);
void clear(Node*& head);
void enqueue(Node*& front, Node*& rear, datatype key);
void dequeue(Node*& front, Node*& rear);
void search(Node* head, Node* rear, datatype key);
void add_mid(Node* head, Node* rear, datatype key);
void del_mid(Node*& head, Node*& rear, datatype key);


#endif


#ifndef LISTS_H
#define LISTS_H

// Use 'int' or another type for datatype if unspecified
typedef int datatype;

struct Node {
    datatype key;
    Node* next;
    Node* prev; // Only relevant for doubly linked lists
};

// Function prototypes
void push(Node*& head, Node*& rear, datatype key);
void pop(Node*& head, Node*& rear);
void show(Node* head);
void show2(Node* front);
void clear(Node*& head);
void enqueue(Node*& head, Node*& rear, datatype key);
void dequeue(Node*& front, Node*& rear);
void search(Node* head, datatype key);
void add_mid(Node*& head, Node*& rear, datatype key);
void del_mid(Node*& head, Node*& rear, datatype key);
void pop_end(Node*& head, Node*& rear); // New function to delete from the end

#endif


#ifndef LISTS_H
#define LISTS_H

#include <string>

struct Node {
    std::string key;
    Node* next;
};

// Stack operations
void push(Node*& head, std::string key);
void pop(Node*& head);
std::string top(Node* head);
bool empty(Node* head);
void show(Node* head);

// Queue operations
void enqueue(Node*& head, Node*& rear, std::string key);
void dequeue(Node*& front, Node*& rear);
void show2(Node* front);

// List operations
void search(Node* head, Node* rear, std::string key);
void add_mid(Node*& head, Node*& rear, std::string key);
void del_mid(Node*& head, Node*& rear, std::string key);
void clear(Node*& head);

#endif

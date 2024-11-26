#ifndef LISTS_H
#define LISTS_H

#include <string>
#include <stack>
#include <queue>

typedef std::stack<int> Stack;
typedef std::queue<int> Queue;

// No need to define push, pop, enqueue, dequeue manually; they are available through std
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

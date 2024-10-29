#ifdef LINLISTS_H
#define LINLISTS_H

struct Node
{
datatype key;
Node* next;
Node* previous; //у випадку двозв’язного списку
};
Node *head, *temp, *front, *rear;

void push(Node*& head, datatype key);
void pop(Node*& head);
void show(Node*& head);

#endif

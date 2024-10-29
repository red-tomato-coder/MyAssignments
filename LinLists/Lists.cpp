#include <iostream>
#include "Lists.h"
using namespace std;

// Push: Add element to the top of the stack
void push(Node*& head, datatype key) {
    Node* newNode = new Node{key, head, nullptr}; // Create new node
    head = newNode; // Set new node as head
}

// Pop: Remove element from the top of the stack
void pop(Node*& head) {
    if (head == nullptr) {
        cout << "The stack is empty, nothing to pop out" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Show: Display all elements in the stack
void show(Node* head) {
    if (head == nullptr) {
        cout << "The stack is empty, nothing to show" << endl;
        return;
    }
    Node* temp = head;
    cout << "Stack Content: ";
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}
void clear(Node*& head) {
    Node* current = head;
    Node* nextNode = nullptr;
    
    while (current != nullptr) {
        nextNode = current->next; // Store the next node
        delete current;            // Delete the current node
        current = nextNode;        // Move to the next node
    }
    
    head = nullptr; // Set head to nullptr after clearing
}

void enqueue(Node*& head, Node*& rear, datatype key) {
    Node* newNode = new Node{key, nullptr};  // Step 1: Create new node

    if (rear == nullptr) {  // Step 2: If the queue is empty
        head = rear = newNode;  // Both front and rear point to the new node
    } else {  // Step 3: Add new node at the rear
        rear->next = newNode;  // Link current rear to new node
        rear = newNode;  // Update rear to point to new node
    }
}

void dequeue(Node* head){
	if (front == nullptr) {  // Check if the queue is empty
        	cout << "The queue is empty, nothing to dequeue." << endl;
        	return;
    	}
	Node* temp = head;
	front = head -> next;
	if(head == nullptr){
		rear = nullptr;
	}

	delete temp;

}

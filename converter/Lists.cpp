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

void show2(Node* front) {
    if (front == nullptr) {
        cout << "The queue is empty, nothing to show" << endl;
        return;
    }
    Node* temp = front;
    cout << "Queue Content: ";
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

void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {  // Check if the queue is empty
        cout << "The queue is empty, nothing to dequeue." << endl;
        return;
    }
    
    Node* temp = front;  // Hold the front node temporarily
    front = front->next; // Move front to the next node

    // If front becomes nullptr after moving, the queue is empty, so set rear to nullptr as well
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;  // Delete the old front node
}

void search(Node* head, Node* rear, datatype key) {
    if (head == nullptr) {
        cout << "No data in linked list\n";
        return;
    }

    Node* current = head;  // Use a traversal pointer
    int i = 0;
    bool found = false;

    while (current != nullptr) {
        if (current->key == key) {  // Check if the current node has the desired key
            found = true;
            cout << "Your searched element is in the position of " << i << endl;
	    break;
        }
        current = current->next;  // Move to the next node
        i++;  // Increment the position counter
    }

    if (!found) {
        cout << "Your searched element has not been found" << endl;
    }
}

void add_mid(Node* head, Node* rear, datatype key) {
	int new_key;
	cout << "Print a wanted value: ";
	cin >> new_key;
	cout << endl;
	Node* current = head;
    
    // Search for the node with the given key
    while (current != nullptr && current->key != key) {
        current = current->next;
    }
    
    // If the node with the key is found
    if (current != nullptr) {
        Node* newNode = new Node{new_key, current->next}; // Create new node
        current = newNode; // Insert new node after the current node
        
        if (current == rear) { // Update rear if we added at the end
            rear = newNode;
        }
    } else {
        cout << "The specified element was not found in the list." << endl;
    }
}

void del_mid(Node*& head, Node*& rear, datatype key) {
    // If the list is empty
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    // If the node to delete is the head
    if (head->key == key) {
        Node* temp = head;
        head = head->next;  // Move head to the next node

        // Update rear if the list is now empty
        if (head == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return;
    }

    // Search for the node with the given key
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr && current->key != key) {
        prev = current;
        current = current->next;
    }

    // If the node with the key is found
    if (current != nullptr) {
        prev->next = current->next;  // Bypass the node to delete

        // Update rear if we deleted the last node
        if (current == rear) {
            rear = prev;
        }

        delete current;
    } else {
        cout << "The specified element was not found." << endl;
    }
}


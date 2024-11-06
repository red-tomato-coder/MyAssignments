#include <iostream>
#include "Lists.h"
using namespace std;

// Push: Add element to the beginning of the list
void push(Node*& head, Node*& rear, datatype key) {
    Node* newNode = new Node{key, head, nullptr};
    if (head != nullptr) {
        head->prev = newNode;
    } else {
        rear = newNode; // If list was empty, rear is also the new node
    }
    head = newNode;
}

// Pop: Remove element from the beginning of the list
void pop(Node*& head, Node*& rear) {
    if (head == nullptr) {
        cout << "The list is empty, nothing to pop out" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        rear = nullptr; // List is now empty
    }
    delete temp;
}

// Pop_end: Remove element from the end of the list
void pop_end(Node*& head, Node*& rear) {
    if (rear == nullptr) {
        cout << "The list is empty, nothing to pop out" << endl;
        return;
    }
    Node* temp = rear;
    rear = rear->prev;
    if (rear != nullptr) {
        rear->next = nullptr;
    } else {
        head = nullptr; // List is now empty
    }
    delete temp;
}

// Show: Display all elements in the list
void show(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty, nothing to show" << endl;
        return;
    }
    Node* temp = head;
    cout << "List Content: ";
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
    Node* newNode = new Node{key, nullptr, rear};
    if (rear == nullptr) {
        head = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {  // Check if the queue is empty
        cout << "The queue is empty, nothing to dequeue." << endl;
        return;
    }
    
    Node* temp = front;  // Hold the front node temporarily
    front = front->next; // Move front to the next node

    if (front != nullptr) {
        front->prev = nullptr;
    } else {
        rear = nullptr; // Queue is now empty
    }

    delete temp;  // Delete the old front node
}

void search(Node* head, datatype key) {
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
        if (current->key == key) {
            cout << "Element found at position: " << position << endl;
            return;
        }
        current = current->next;
        position++;
    }
    cout << "Element not found." << endl;
}

void add_mid(Node*& head, Node*& rear, datatype key) {
    datatype new_key;
    cout << "Enter the new value to insert: ";
    cin >> new_key;
    Node* current = head;
    while (current != nullptr && current->key != key) {
        current = current->next;
    }
    if (current != nullptr) {
        Node* newNode = new Node{new_key, current->next, current};
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            rear = newNode; // Update rear if added at the end
        }
        current->next = newNode;
    } else {
        cout << "Element not found." << endl;
    }
}

void del_mid(Node*& head, Node*& rear, datatype key) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr && current->key != key) {
        current = current->next;
    }
    if (current != nullptr) {
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            rear = current->prev;
        }
        delete current;
    } else {
        cout << "Element not found." << endl;
    }
}


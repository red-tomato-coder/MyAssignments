#include "Lists.h"
#include <iostream>

void push(Node*& head, std::string key) {
    Node* newNode = new Node{key, head};
    head = newNode;
}

void pop(Node*& head) {
    if (head == nullptr) {
        std::cout << "The stack is empty, nothing to pop out\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

std::string top(Node* head) {
    if (head != nullptr) {
        return head->key;
    }
    return "";
}

bool empty(Node* head) {
    return head == nullptr;
}

void show(Node* head) {
    if (head == nullptr) {
        std::cout << "The stack is empty, nothing to show\n";
        return;
    }
    Node* temp = head;
    std::cout << "Stack Content: ";
    while (temp != nullptr) {
        std::cout << temp->key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void show2(Node* front) {
    if (front == nullptr) {
        std::cout << "The queue is empty, nothing to show\n";
        return;
    }
    Node* temp = front;
    std::cout << "Queue Content: ";
    while (temp != nullptr) {
        std::cout << temp->key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void clear(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void enqueue(Node*& head, Node*& rear, std::string key) {
    Node* newNode = new Node{key, nullptr};
    if (rear == nullptr) {
        head = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        std::cout << "The queue is empty, nothing to dequeue.\n";
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

void search(Node* head, Node* rear, std::string key) {
    if (head == nullptr) {
        std::cout << "No data in linked list\n";
        return;
    }
    Node* current = head;
    int i = 0;
    bool found = false;
    while (current != nullptr) {
        if (current->key == key) {
            found = true;
            std::cout << "Your searched element is in position " << i << std::endl;
            break;
        }
        current = current->next;
        i++;
    }
    if (!found) {
        std::cout << "Your searched element has not been found\n";
    }
}

void add_mid(Node*& head, Node*& rear, std::string key) {
    std::string new_key;
    std::cout << "Enter a wanted value: ";
    std::cin >> new_key;
    
    Node* current = head;
    while (current != nullptr && current->key != key) {
        current = current->next;
    }
    
    if (current != nullptr) {
        Node* newNode = new Node{new_key, current->next};
        current->next = newNode;
        if (current == rear) {
            rear = newNode;
        }
    } else {
        std::cout << "The specified element was not found in the list.\n";
    }
}

void del_mid(Node*& head, Node*& rear, std::string key) {
    if (head == nullptr) {
        std::cout << "The list is empty.\n";
        return;
    }

    if (head->key == key) {
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return;
    }

    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        prev->next = current->next;
        if (current == rear) {
            rear = prev;
        }
        delete current;
    } else {
        std::cout << "The specified element was not found.\n";
    }
}

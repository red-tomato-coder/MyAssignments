#include <iostream>
#include "Lists.h"
using namespace std;

Node* head = nullptr; // Initialize head to nullptr
Node* front = nullptr;  // Initialize front pointer for queue
Node* rear = nullptr;

void First(){
	int choice;
    	datatype value;

    	while (true) {
        	cout << "\nMENU:\n"
             	<< "1. PUSH\n"
             	<< "2. POP\n"
             	<< "3. SHOW\n"
             	<< "4. EXIT\n"
            	<< "Enter input: ";
        	cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                push(head, value);
                break;

            case 2:
                pop(head);
                break;

            case 3:
                show(head);
                break;

            case 4:
                cout << "Exiting...\n" << endl;
                return;

            default:
                cout << "Invalid choice" << endl;
        }
    }

}

void Second(){
int choice;
    	datatype value;

    	while (true) {
        	cout << "\nMENU:\n"
             	<< "1. INQUEUE\n"
             	<< "2. DEQUEUE\n"
             	<< "3. SHOW\n"
             	<< "4. EXIT\n"
            	<< "Enter input: ";
        	cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                enqueue(front, rear, value);
                break;

            case 2:
                dequeue(front, rear);
                break;

            case 3:
                show2(head);
                break;

            case 4:
                cout << "Exiting...\n" << endl;
		clear(head);
                return;

            default:
                cout << "Invalid choice" << endl;
        }
    }
	
}

void Third(){
	int choice;
	datatype key;
	
	while(true){
	cout << "MENU:\n"
	<< "1. Add begin\n"
	<< "2. Add end\n"
	<< "3. Delete begin\n"
	<< "4. Delete end\n"
	<< "5. Search\n"
	<< "6. Add an element after found element\n"
	<< "7. Delete found element\n"
	<< "8. Show\n"
	<< "Type choice: ";

	cin >> choice;

	switch(choice){
		case 1:
			cout << "Type an added element: ";
			cin >> key;
			cout << endl;
			push(head, key);
			if (rear == nullptr) rear = head;
			break;
		case 2:
			cout << "Type an added element: ";
			cin >> key;
			cout << endl;
			enqueue(front, rear, key);
			break;
		case 3:
			dequeue(front, rear);
			break;
		case 4:
			pop(rear);
			cout << endl;
			break;
		case 5:
			cout << "Type element to search: ";
			cin >> key;
			cout << endl;
			search(head, rear, key);
			break;
		case 6:
			cout << "Type element after which needed to be placed a number: ";
			cin >> key;
			cout << endl;
			add_mid(head, rear, key);
			break;
		case 7:
			cout << "Type element which should be deleted: ";
			cin >> key;
			cout << endl;
			del_mid(head, rear, key);
			break;
		case 8:
			show(head);
			break;

	}}
}

void menu() {
	while(true){
	int menuchoice;
	cout<<"CHOOSE PART: \n";
	cin>>menuchoice;
	switch(menuchoice){
		case 1:
			First();
			break;
		case 2:
			Second();
			break;
		case 3:
			Third();
			break;
		default:
			cout<<"Wrong option!";
			menu();
			break;
	}
    }
}


int main() {
    menu();
    return 0;
}


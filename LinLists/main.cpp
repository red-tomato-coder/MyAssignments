#include <iostream>
#include "Lists.h"
using namespace std;

Node* head = nullptr; // Initialize head to nullptr

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
             	<< "1. ENQUEUE\n"
             	<< "2. DEQUEUE\n"
             	<< "3. SHOW\n"
             	<< "4. EXIT\n"
            	<< "Enter input: ";
        	cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                enqueue(head, value);
                break;

            case 2:
                enqueue(head);
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

void menu() {
	while(true){
	int menuchoice;
	cout<<"CHOOSE PART: \n";
	cin>>menuchoice;
	switch(menuchoice){
		case 1:
			First();
			break;
		case
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


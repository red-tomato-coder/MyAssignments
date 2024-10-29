#include<iostream>

using namespace std;

void push(Node*& head, datatype key){
	Node* NewNode = newNode{key, head}
	top = NewNode
}
void pop(Node*& head, datatype key){
	if(head == nullptr){
		cout<<"The stack is empty, nothing to pop out";
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
}
void show(Node* head){
	if(head == nullptr){
		cout<<"The stack is empty, nothing to show";
		return;
	}
	Node* temp = head;
	cout<<"Stack Content: ";
	while(head!=nullptr){
		cout<< temp->key<< " ";
		temp = temp -> next;

	}
	cout<<endl;
}

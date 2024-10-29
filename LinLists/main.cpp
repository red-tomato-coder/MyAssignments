#include <iostream>
#include "Lists.h"

using namespace std;

void menu(){
	int choice;
	datatype value;
	cout<<"MENU:\n"<<"1. PUSH\n"<<"2. POP\n"<<"3. SHOW\n"<<"Enter input: \n";
	cin>>choice;
	switch (choice)
    case 1:
      cout<<"Enter a value to push: "; 
      cin>>value; 
      push(head, value); 
      break;
	  case 2: 
      pop(head); 
      break;
	  case 3: 
      show(head); 
      break;
	  default: 
      cout<<"Invalid choice"<<endl;
  }
}

int main(){
	menu();
	return 0;
}

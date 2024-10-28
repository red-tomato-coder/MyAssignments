#include<iostream>
#include"Sorting.h"

using namespace std;

int main(){
	int b;
	int l;
	int r;
	int* arr = new int[10];
       	for(int i=0; i<10; i++){
		arr[i]=9-i;
	}	
	cout<<"Please choose sorting method"<<"\n"<<"1. Bubble \n"<<"2. Selection \n"<<"3. Insertion\n";
	cin>>b;
	cout<<"type range:\n";
	cin>>l>>r;
	if(b==1){
		BUBBLE(arr, l, r);
	}
	if(b==2){
		SELECTION(arr, l, r);
	}
	if(b==3){
		INSERTION(arr, l, r);
	}
	return 0;
}

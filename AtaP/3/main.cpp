#include <iostream>

using namespace std;

double FACTORIAL(int n){
  if(n==0){
    return 1;
  }
  else{
    return n * FACTORIAL(n-1);
  }
}

int main(){
  int i;
  cout<<"input i\n";
  cin>>i;
  cout<<endl<<FACTORIAL(i);
  return 0;
}

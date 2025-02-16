#include <iostream>
#include <vector>

using namespace std;

double f(int x){
  return x-2;
}

int main(){
  vector<double> Xe;
  vector<double> Ye;
  for(int i = 0; i < 5; i++){
    Xe.push_back(i);
    Ye.push_back(f(i));
  }
  cout<<"Xe: \n";
  for(int i = 0; i < 5; i++){
    cout<<i<<" "<<Xe[i]<<endl;
  }
  cout<<"Ye: \n";
  for(int i = 0; i < 5; i++){
    cout<<i<<" "<<Ye[i]<<endl;
  }
}

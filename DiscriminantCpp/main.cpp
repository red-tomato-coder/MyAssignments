#include<iostream>
#include<cmath>

using namespace std;

int main(){
int a, b, c, D, x1, x2;
cout << "Type a, b and c";
cin >> a
>> b
>> c;

D = pow(b, 2) - 4 * a * c;
switch(D){
  case(D<0):
    cout << "Discriminant is less than 0. no roots";
    return;

  case(0):
    cout << "Discriminant is 0, one root found: " << (b - sqrt(D))/(2*a);
    return;
  case(D>0):
    cout << "Two roots are found\n"
      <<"x1 = " << (b - sqrt(D))/(2*a) << endl
      <<"x2 = " << (b + sqrt(D))/(2*a) << endl;
return 0;

}
}

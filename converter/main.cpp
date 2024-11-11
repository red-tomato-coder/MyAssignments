#include <iostream>
#include <vector>

using namespace std;

int* stringToEquation(){
  string e;
  cout << "\nType your equation: ";
  cin >> e;
  cout << endl;
  
  // Convert the string to a character array and return the pointer
  // However, remember this is still risky in real scenarios
  return (int*)e.c_str();
}

int main(){
  int choice;
  cout << "Menu:\n1.Infix => Prefix\n2. Infix => Suffix\n";
  cin >> choice;
  int* equation = stringToEquation();
  switch (choice) {
    case 1:
      infixToPrefix(equation);
      break;
    case 2:
      infixToSuffix(equation);
      break;
    default:
      
      break;
  }
}

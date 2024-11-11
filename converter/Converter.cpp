#include<iostream>
#include<array>
#include<algorithm>
#include "Lists.h"

using namespace std;

struct Node{
	char key
	Node* next;
}

int precedence(char op){
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  if (op == '^') return 3;
}

bool isOperator(char c){
  return c == '+' || c == '-' || c == '*' || op == '/' || op == '^';
}

infixToPrefix(int* equation){

}
infixToSuffix(int* equation){

}
prefixToInfix(int* equation){

}
suffixToInfix(int* equation){

}

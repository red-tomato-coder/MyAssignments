#include<iostream>
#include<array>
#include<algorithm>
#include "Lists.h"

using namespace std;

struct Node{
	char key
	Node* next;
}

Node* head = nullptr;
Node* front = nullptr;
Node* rear = nullptr;

int precedence(char op){
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  if (op == '^') return 3;
}

bool isOperator(char c){
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPrefix(int* equation){

}
void infixToSuffix(string equation){
  string result = "";
  for(int i = 0; i < equation.length; i++){
    char c = equation[i];

    if(isalnum(c)) result +=c;
    else if(c == '(') push(head, rear, '(');
    else if (c == ')'){
      while(top(head)=='('){//Бля походу доведеться модифіковувати минулу лабу
          result+= top(head);
    }
      pop(head)
    }
    else{
      while(empty(head) && precedence(c) <= precedence(top(head))){
        result+= top(head)
        pop(head);
      }
      push(head, c);
    }
}
    while(!empty(head)){
      result += top(head);
      pop(head);//Girls gives me a headache, boys gives me a head
    }
}
void prefixToInfix(int* equation){

}
void suffixToInfix(int* equation){

}

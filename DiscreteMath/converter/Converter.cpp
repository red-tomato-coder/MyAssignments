#include "Converter.h"
#include "Lists.h"
#include <algorithm>
#include <iostream>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

std::string infixToPrefix(std::string equation) {
    // Reverse the equation
    std::reverse(equation.begin(), equation.end());
    
    // Replace ( with ) and vice versa
    for (char& c : equation) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    
    // Convert to postfix
    std::string postfix = infixToSuffix(equation);
    
    // Reverse again to get prefix
    std::reverse(postfix.begin(), postfix.end());
    return postfix;
}

std::string infixToSuffix(std::string equation) {
    Node* stack = nullptr;
    std::string result;
    
    for (char c : equation) {
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            push(stack, std::string(1, c));
        }
        else if (c == ')') {
            // Pop and output until matching '(' is found
            while (!empty(stack) && top(stack) != "(") {
                result += top(stack);
                pop(stack);
            }
            pop(stack); // Remove '('
        }
        else if (isOperator(c)) {
            // Simply push operator to stack
            push(stack, std::string(1, c));
        }
    }
    
    // Pop remaining operators from stack
    while (!empty(stack)) {
        result += top(stack);
        pop(stack);
    }
    
    clear(stack);
    return result;
}

std::string prefixToInfix(std::string equation) {
    Node* stack = nullptr;
    
    // Read from right to left
    for (int i = equation.length() - 1; i >= 0; i--) {
        char c = equation[i];
        
        if (isOperator(c)) {
            std::string op1 = top(stack);
            pop(stack);
            std::string op2 = top(stack);
            pop(stack);
            std::string temp = "(" + op1 + c + op2 + ")";
            push(stack, temp);
        } else {
            push(stack, std::string(1, c));
        }
    }
    
    std::string result = top(stack);
    clear(stack);
    return result;
}

std::string suffixToInfix(std::string equation) {
    Node* stack = nullptr;
    
    for (char c : equation) {
        if (isOperator(c)) {
            std::string op2 = top(stack);
            pop(stack);
            std::string op1 = top(stack);
            pop(stack);
            std::string temp = "(" + op1 + c + op2 + ")";
            push(stack, temp);
        } else {
            push(stack, std::string(1, c));
        }
    }
    
    std::string result = top(stack);
    clear(stack);
    return result;
}

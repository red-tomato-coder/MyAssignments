
#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include "Lists.h"  // Includes the linked list operations

// Function prototypes for infix to postfix, infix to prefix, and other conversions
int precedence(char op);
bool isOperator(char c);

// Conversion functions
void infixToPostfix(Node*& stack, Node*& output, const std::string& infix);
void infixToPrefix(Node*& stack, Node*& output, const std::string& infix);
void prefixToInfix(Node*& stack, const std::string& prefix);
void suffixToInfix(Node*& stack, const std::string& suffix);

#endif


#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

int precedence(char c);
//bool isOperator(char c);
std::string infixToPrefix(std::string equation);
std::string infixToSuffix(std::string equation);
std::string prefixToInfix(std::string equation);
std::string suffixToInfix(std::string equation);

#endif

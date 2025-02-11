#include <iostream>
#include <string>
#include "Converter.h"

// Only use specific symbols we need
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int choice;
    string equation;
    
    while (true) {
        cout << "\nExpression Converter Menu:\n"
             << "1. Infix to Prefix\n"
             << "2. Infix to Suffix (Postfix)\n"
             << "3. Prefix to Infix\n"
             << "4. Suffix to Infix\n"
             << "5. Exit\n"
             << "Enter your choice (1-5): ";
        
        cin >> choice;
        
        if (choice == 5) break;
        
        cout << "Enter your expression: ";
        cin >> equation;
        
        try {
            switch (choice) {
                case 1:
                    cout << "Prefix: " << infixToPrefix(equation) << endl;
                    break;
                case 2:
                    cout << "Suffix: " << infixToSuffix(equation) << endl;
                    break;
                case 3:
                    cout << "Infix: " << prefixToInfix(equation) << endl;
                    break;
                case 4:
                    cout << "Infix: " << suffixToInfix(equation) << endl;
                    break;
                default:
                    cout << "Invalid choice! Please select 1-5.\n";
            }
        } catch (const std::exception& e) {
            cout << "Error: Invalid expression\n";
        }
    }
    
    return 0;
}

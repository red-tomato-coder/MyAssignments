#include "Trees.h"
#include <iostream>

int main() {
    Node* root = nullptr;

    while (true) {
        int choice;
        std::cout << "1. Створити\\доповнити дерево\n"
                  << "2. Показати дерево\n"
                  << "3. Pre-order\n"
                  << "4. Post-order\n"
                  << "5. In-order\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (root == nullptr) {
                    int input_key, left_key, right_key;
                    std::cout << "Введіть значення батьківського елементу: ";
                    std::cin >> input_key;
                    //std::cout << "\n";

                    std::cout << "Тепер введіть наступні два елементи для корення (лівий та правий елементи): ";
                    std::cin >> left_key >> right_key;

                    root = CreateTree(input_key, left_key, right_key);
                } else {
                    int looking_for_node;
                    std::cout << "Введіть до якого елементу хочете доповнити дерево: ";
                    std::cin >> looking_for_node;
                    std::cout << "\n";
                    CreateNode(root, looking_for_node);  // Pass the root node here
                }
                break;

            case 2:
                PrintTree(root);
                break;

            case 3:
                PreOrder(root);
                std::cout << std::endl;
                break;

            case 4:
                PostOrder(root);
                std::cout << std::endl;
                break;

            case 5:
                InOrder(root);
                std::cout << std::endl;
                break;

            default:
                std::cout << "Щось пішло не так\n";
                break;
        }
    }

    return 0;
}

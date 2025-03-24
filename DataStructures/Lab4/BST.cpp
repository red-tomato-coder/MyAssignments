#include "Trees.h"
#include <iostream>

int main() {
    Node* root = nullptr;

    while (true) {
        int choice;
        std::cout 
            << "1. Створити/доповнити BST дерево\n"
            << "2. Видалити вузол BST\n"
            << "3. Переглянути наслідувача/предка вузла\n"
            << "4. Перегляд дерева\n"
            << "5. Обхід\n"
            << "6. Згенерувати дерево\n"
            << "Введіть ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                if (root == nullptr) {
                    int key, first_key, second_key;
                    std::cout << "Введіть ключ для кореневого вузла: ";
                    std::cin >> key;
                    std::cout << "Введіть ключі для лівого та правого вузлів: ";
                    std::cin >> first_key >> second_key;
                    root = CreateRootBST(key, first_key, second_key);
                } else {
                    int key, ChildKey;
                    std::cout << "Введіть ключ, до якого хочете додати вузли: ";
                    std::cin >> key;
                    Node* parentNode = SearchNodeBST(root, key);
                    if (parentNode) {
                        std::cout << "Введіть ключ для наступного вузла: ";
                        std::cin >> ChildKey;
                        InsertNodeBST(root, parentNode, ChildKey);
                    } else {
                        std::cout << "Вузол з таким ключем не знайдено.\n";
                    }
                }
                break;
            }
            case 2: {
                int key;
                std::cout << "Введіть ключ вузла, який хочете видалити: ";
                std::cin >> key;
                Node* delNode = SearchNodeBST(root, key);
                if (delNode) {
                    DeleteNodeBST(root, delNode);
                } else {
                    std::cout << "Вузол з таким ключем не знайдено.\n";
                }
                break;
            }
            case 3: {
                int key;
                std::cout << "Введіть ключ вузла, для якого хочете знайти наслідувача та предка: ";
                std::cin >> key;
                Node* targetNode = SearchNodeBST(root, key);
                if (targetNode) {
                    Node* successorNode = SuccessorNodeBST(targetNode);
                    Node* predecessorNode = PredecessorNodeBST(targetNode);

                    if (successorNode) {
                        std::cout << "Наслідувач: " << successorNode->key << "\n";
                    } else {
                        std::cout << "Наслідувач не знайдено (це максимальний вузол).\n";
                    }

                    if (predecessorNode) {
                        std::cout << "Предок: " << predecessorNode->key << "\n";
                    } else {
                        std::cout << "Предок не знайдено (це мінімальний вузол).\n";
                    }
                } else {
                    std::cout << "Вузол з таким ключем не знайдено.\n";
                }
                break;
            }
            case 4: {
                PrintTree(root);
                break;
            }
            case 5:{
                std::cout << "PreOrder: ";
                PreOrder(root);
                std::cout << std::endl;
                std::cout << "PostOrder: ";
                PostOrder(root);
                std::cout << std::endl;
                std::cout << "InOrder: ";
                InOrder(root);
                std::cout << std::endl;
                break;
            }
            case 6:
                Recursive(root);
                break;
            default: {
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
            }
        }
    }

    return 0;
}

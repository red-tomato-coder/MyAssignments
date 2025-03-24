#include "Trees.h"
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>

Node* CreateTree(int key, int left, int right) {
    Node* root = new Node(key);
    root->left = new Node(left);
    root->right = new Node(right);
    return root;
}

int treeHeight(Node* root) {
    if (!root) return 0;
    return std::max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

void printSpaces(int count) {
    for (int i = 0; i < count; ++i)
        std::cout << " ";
}

void PrintTree(Node* root) {
    if (root == nullptr) {
      std::cout << "Дерево пусте" << std::endl;
        return;
    }
    
    int maxLevel = treeHeight(root);
    std::vector<Node*> nodes;
    nodes.push_back(root);
    int level = 1;
    
    while (level <= maxLevel) {
        int floor = maxLevel - level;
        int edgeLines = (int)pow(2, std::max(floor - 1, 0));
        int firstSpaces = (int)pow(2, floor) - 1;
        int betweenSpaces = (int)pow(2, floor + 1) - 1;
        
        printSpaces(firstSpaces);
        std::vector<Node*> newNodes;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == nullptr) {
                std::cout << " ";
                newNodes.push_back(nullptr);
                newNodes.push_back(nullptr);
            } else {
                std::cout << nodes[i]->key;
                newNodes.push_back(nodes[i]->left);
                newNodes.push_back(nodes[i]->right);
            }
            printSpaces(betweenSpaces);
        }
        std::cout << "\n";
        
        for (int i = 1; i <= edgeLines; i++) {
            for (int j = 0; j < nodes.size(); j++) {
                printSpaces(firstSpaces - i);
                if (nodes[j] == nullptr) {
                    printSpaces(edgeLines * 2 + i + 1);
                    continue;
                }
                if (nodes[j]->left != nullptr)
                    std::cout << "/";
                else
                    std::cout << " ";
                
                printSpaces(i * 2 - 1);
                
                if (nodes[j]->right != nullptr)
                    std::cout << "\\";
                else
                    std::cout << " ";
                
                printSpaces(edgeLines * 2 - i);
            }
            std::cout << "\n";
        }
        
        nodes = newNodes;
        level++;
    }
}

void CreateNode(Node* root, int ParentKey) {
    int left_key, right_key;
    Node* ParentNode = FindNode(root, ParentKey);

    if (ParentNode == nullptr) {
        std::cout << "Такого вузла не знайдено" << std::endl;
        return;
    }

    if(ParentNode -> left == nullptr && ParentNode -> right == nullptr){
      std::cout << "Введіть ключі для лівого та правого вузла: ";
      std::cin >> left_key >> right_key;
      if (FindNode(root, left_key) != nullptr || FindNode(root, right_key) != nullptr){
        std::cout << "Такий вузол вже існує" << std::endl;
        return;
      }
      ParentNode->left = new Node(left_key);
      ParentNode->right = new Node(right_key);
    }
    else{
      std::cout << "Вузол вже заповнений" << std::endl;
      return;
    }
}

Node* FindNode(Node* root, int ParentKey) {
    if (root == nullptr) {
        return nullptr;
    }

    std::stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* currentNode = st.top();
        st.pop();

        if (currentNode->key == ParentKey) {
            return currentNode;
        }

        if (currentNode->right) {
            st.push(currentNode->right);
        }
        if (currentNode->left) {
            st.push(currentNode->left);
        }
    }

    return nullptr;
}

void InOrder(Node* root) {
    if (root == nullptr) return;

    InOrder(root->left);
    std::cout << root->key << " ";
    InOrder(root->right);
}

void PostOrder(Node* root) {
    if (root == nullptr) return;

    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->key << " ";
}

void PreOrder(Node* root) {
    if (root == nullptr) return;

    std::cout << root->key << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

/*
 _____________________________________________________________
/                                                              \
|===========================ЧАСТИНА 2==========================|
\______________________________________________________________/

*/

Node* CreateRootBST(int key, int first_key, int second_key) {
    Node* root = new Node(key);

    if ((first_key < key && second_key > key) || (first_key > key && second_key < key)) {
        root->left = new Node(first_key);
        root->right = new Node(second_key);
        root->left->parent = root;
        root->right->parent = root;
        if (root->left) {
          root->left->left = nullptr;
          root->left->right = nullptr;
        }
        if (root->right) {
          root->right->left = nullptr;
          root->right->right = nullptr;
        }
    } 
    else {
        std::cout << "Умова BST недотримана, зміни не прийняті" << std::endl;
        delete root;
        return nullptr;
    }

    PrintTree(root);
    return root;
}

void InsertNodeBST(Node* root, Node* parentNode, int ChildKey) {
    if (ChildKey == parentNode->key) {
        std::cout << "Такий вузол вже існує\n";
        return;
    }

    if (ChildKey > parentNode->key) {
        if (parentNode->right == nullptr) {
            Node* newNode = new Node(ChildKey);
            newNode->parent = parentNode;
            newNode->left = nullptr;
            newNode->right = nullptr;
            parentNode->right = newNode;
        } else {
            std::cout << "Правий вузол вже зайнятий\n";
            return;
        }
    } else {
        if (parentNode->left == nullptr) {
            Node* newNode = new Node(ChildKey);
            newNode->key = ChildKey;
            newNode->parent = parentNode;
            newNode->left = nullptr;
            newNode->right = nullptr;
            parentNode->left = newNode;
        } else {
            std::cout << "Лівий вузол вже зайнятий\n";
            return;
        }
    }

    PrintTree(root);
}

Node* SearchNodeBST(Node* root, int SearchedKey) {
  if (root == nullptr) return nullptr;

  if (SearchedKey == root->key) return root;
  if (SearchedKey < root->key) return SearchNodeBST(root->left, SearchedKey);
  return SearchNodeBST(root->right, SearchedKey);
}

void DeleteNodeBST(Node*& root, Node* delNode) {
  if(root != nullptr){
    if (delNode == nullptr) {
        std::cout << "Вузол для видалення не знайдено\n" << std::endl;
        return;
    }

    if (delNode->left == nullptr && delNode->right == nullptr) { //Якщо листок
        if (delNode == root) {
            delete root;
            root = nullptr;
        } else {
            if (delNode->parent->left == delNode)
                delNode->parent->left = nullptr;
            else
                delNode->parent->right = nullptr;
            delete delNode;
        }
    }

    else if (delNode->left == nullptr || delNode->right == nullptr) { //якщо 1 гілка
        Node* child = (delNode->left != nullptr) ? delNode->left : delNode->right;
        if (delNode == root) {
            root = child;
            child->parent = nullptr;
            delete delNode;
        } else {
            if (delNode->parent->left == delNode)
                delNode->parent->left = child;
            else
                delNode->parent->right = child;
            child->parent = delNode->parent;
            delete delNode;
        }
    }

    else {                                                    //Якщо 2 гілки
        Node* successor = SuccessorNodeBST(delNode);
        delNode->key = successor->key;
        DeleteNodeBST(root, successor); // Рекурсивно видаляється
    }
    PrintTree(root);
  }
  else{
    std::cout << "Дерева не існує";
  }
}


Node* SuccessorNodeBST(Node* node) {
    if (node == nullptr) return nullptr;

    if (node->right != nullptr) {
        Node* current = node->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* PredecessorNodeBST(Node* node){
  if (node == nullptr) return nullptr;

    if (node->right != nullptr) {
        Node* current = node->left;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void Recursive(Node*& root){
  if(root == nullptr){
      root = new Node(1);
      root->left = new Node(2);
      root->right = new Node(3);
      root->left->left = new Node(4);
      root->left->right = new Node(5);
      root->right->left = new Node(6);
      root->right->right = new Node(7);
      return;
  }
  std::cout << "Дерево вже існує";
  return;
}

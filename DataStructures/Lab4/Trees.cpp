#include "Trees.h"
#include <stack>
#include <vector>
#include <queue>
#include <iostream>

Node* CreateTree(int key, int left, int right) {
    Node* root = new Node(key);
    root->left = new Node(left);
    root->right = new Node(right);
    return root;
}

void PrintTree(Node* root) {
    if (root == nullptr) {
        std::cout << "Дерево пусте" << std::endl;
        return;
    }

    std::queue<Node*> q;
    q.push(root);
    std::cout << "==============\n";
    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front();
            q.pop();
            currentLevel.push_back(currentNode->key);

            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }

        for (int key : currentLevel) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "==============\n";
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

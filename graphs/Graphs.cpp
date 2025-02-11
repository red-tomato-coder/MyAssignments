#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include "Graphs.h"

std::vector<Node*> graph = {
    new Node{"1 2 3 6 7", nullptr},
    new Node{"0 6 7", nullptr},
    new Node{"0", nullptr},
    new Node{"0 4 5", nullptr},
    new Node{"3 5", nullptr},
    new Node{"3 4", nullptr},
    new Node{"0 1", nullptr}, 
    new Node{"0 1 7", nullptr},
    new Node{"0 1 6", nullptr}};

void initializeGraph(int numNodes) {
    graph.resize(numNodes, nullptr);
}

void DFSRecursive(int node, std::vector<bool>& visited) {
    if (node < 0 || node >= graph.size()) {
        std::cerr << "Error: Invalid node index " << node << ".\n";
        return;
    }

    if (visited[node]) return;

    visited[node] = true;
    std::cout << node + 1 << " ";
    Node* currentNode = graph[node];
    if (currentNode == nullptr) {
        std::cerr << "Error: Node " << node << " is null.\n";
        return;
    }

    for (const char& neighborChar : currentNode->key) {
        if (neighborChar != ' ') {
            int neighbor = neighborChar - '0'; // Convert char to int
            if (neighbor >= 0 && neighbor < graph.size()) {
                DFSRecursive(neighbor, visited);
            } else {
                std::cerr << "Error: Neighbor index " << neighbor
                          << " out of bounds for node " << node << ".\n";
            }
        }
    }
}

void DFSNonRecursive(int startNode) {
    if (startNode < 0 || startNode >= graph.size()) {
        std::cerr << "Error: Start node index " << startNode << " out of bounds.\n";
        return;
    }

    std::vector<bool> visited(graph.size(), false);
    std::stack<int> stack;
    stack.push(startNode);

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (node < 0 || node >= graph.size()) {
            std::cerr << "Error: Node index " << node << " out of bounds.\n";
            continue; // Skip invalid nodes
        }

        if (!visited[node]) {
            visited[node] = true;
            std::cout << node + 1 << " ";

            Node* currentNode = graph[node];
            if (currentNode == nullptr) {
                std::cerr << "Error: Node " << node << " is null.\n";
                continue; // Skip null nodes
            }

            // Push neighbors to stack
            for (const char& neighborChar : currentNode->key) {
                if (neighborChar != ' ') {
                    int neighbor = neighborChar - '0'; // Convert char to int
                    if (neighbor >= 0 && neighbor < graph.size()) {
                        stack.push(neighbor);
                    } else {
                        std::cerr << "Error: Neighbor index " << neighbor
                                  << " out of bounds for node " << node << ".\n";
                    }
                }
            }
        }
    }
}


void BFS(int startNode) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> queue; // Use std::queue
    queue.push(startNode);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        if (!visited[node]) {
            visited[node] = true;
            std::cout << node + 1 << " "; 
            for (const char& neighbor : graph[node]->key) {
                if (neighbor != ' ' && !visited[neighbor - '0']) {
                    queue.push(neighbor - '0');
                }
            }
        }
    }
}

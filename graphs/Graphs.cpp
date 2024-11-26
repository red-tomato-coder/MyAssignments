#include "Lists.h"
#include <vector>
#include <iostream>
#include "Graphs.h"

// Define graph as a global variable **only here** (source file)
std::vector<Node*> graph = {
    new Node{"1", nullptr},     // 0
    new Node{"0 2 3 4", nullptr}, // 1
    new Node{"0 1", nullptr},     // 2
    new Node{"1 5", nullptr},     // 3
    new Node{"1", nullptr},      // 4
    new Node{"3 6 7 8", nullptr}, // 5
    new Node{"5", nullptr},      // 6
    new Node{"5 8", nullptr},    // 7
    new Node{"5 7 9", nullptr},  // 8
    new Node{"8", nullptr},      // 9
};

// Initialize graph or add nodes to it as needed
void initializeGraph(int numNodes) {
    graph.resize(numNodes, nullptr);  // Example: resize to `numNodes` and initialize with nullptr
}

void DFSRecursive(int node, std::vector<bool>& visited) {
    visited[node] = true;
    std::cout << node << " ";

    for (const char& neighbor : graph[node]->key) {
        if (neighbor != ' ' && !visited[neighbor - '0']) {
            DFSRecursive(neighbor - '0', visited);
        }
    }
}

void DFSNonRecursive(int startNode) {
    std::vector<bool> visited(graph.size(), false);
    Stack stack;
    stack.push(startNode);  // Use std::stack push method

    while (!stack.empty()) {
        int node = stack.top();  // Use std::stack top method
        stack.pop(); // Use std::stack pop method

        if (!visited[node]) {
            visited[node] = true;
            std::cout << node << " ";

            // Push all adjacent unvisited nodes onto the stack
            for (const char& neighbor : graph[node]->key) {
                if (neighbor != ' ' && !visited[neighbor - '0']) {
                    stack.push(neighbor - '0');
                }
            }
        }
    }
}

void BFS(int startNode) {
    std::vector<bool> visited(graph.size(), false);
    Queue queue;
    queue.push(startNode);  // Use std::queue push method

    while (!queue.empty()) {
        int node = queue.front();  // Use std::queue front method
        queue.pop(); // Use std::queue pop method

        if (!visited[node]) {
            visited[node] = true;
            std::cout << node << " ";

            // Enqueue all adjacent unvisited nodes
            for (const char& neighbor : graph[node]->key) {
                if (neighbor != ' ' && !visited[neighbor - '0']) {
                    queue.push(neighbor - '0');
                }
            }
        }
    }
}

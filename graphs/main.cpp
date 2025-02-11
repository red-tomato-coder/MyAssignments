#include <iostream>
#include <vector>
#include "Graphs.h"

int main() {
    std::cout << "Graph contents:\n";
    for (size_t i = 0; i < graph.size(); ++i) {
        if (graph[i] == nullptr) {
            std::cerr << "Error: Node " << i << " is null.\n";
        } else {
            std::cout << "Node " << i << " key: " << graph[i]->key << "\n";
        }
    }

    // Ensure graph size matches expectations
    if (graph.size() != 9) {
        std::cerr << "Error: Graph size is " << graph.size() << ", expected 8.\n";
        return 1;
    }

    std::cout << "DFS Recursive:\n";
    std::vector<bool> visited(graph.size(), false);
    DFSRecursive(0, visited);
    std::cout << "\n";

    std::cout << "DFS Non-Recursive:\n";
    DFSNonRecursive(0);
    std::cout << "\n";

    std::cout << "BFS:\n";
    BFS(0);
    std::cout << "\n";

    return 0;
}


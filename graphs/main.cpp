#include <iostream>
#include "Lists.h" // Include your custom library for managing linked lists
#include "Graphs.h"

int main() {
    std::cout << "DFS Recursive:\n";
    std::vector<bool> visited(9, false);
    DFSRecursive(0, visited);  // Start DFS from node 0
    std::cout << "\n";

    std::cout << "DFS Non-Recursive:\n";
    DFSNonRecursive(0);  // Start DFS from node 0
    std::cout << "\n";

    std::cout << "BFS:\n";
    BFS(0);  // Start BFS from node 0
    std::cout << "\n";

    return 0;
}


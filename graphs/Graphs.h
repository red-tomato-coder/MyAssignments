#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <string>

struct Node {
    std::string key;
    Node* next;
};

extern std::vector<Node*> graph; // Declare graph as an external variable

void initializeGraph(int numNodes);
void DFSRecursive(int node, std::vector<bool>& visited);
void DFSNonRecursive(int startNode);
void BFS(int startNode);

#endif


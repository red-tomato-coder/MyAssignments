#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <string>
#include "Lists.h"

// Function prototypes
void DFSRecursive(int node, std::vector<bool>& visited);
void DFSNonRecursive(int startNode);
void BFS(int startNode);

#endif // GRAPHS_H


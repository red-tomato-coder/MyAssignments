#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<Node*> graph = {
    new Node{"1 2", nullptr},     // 0
    new Node{"0 2 4 6", nullptr}, // 1
    new Node{"0 1 3 5", nullptr},     // 2
    new Node{"2", nullptr},     // 3
    new Node{"1", nullptr},      // 4
    new Node{"1 2, 6", nullptr}, // 5
    new Node{"1 5", nullptr},      // 6
};

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph)

int main(){

}

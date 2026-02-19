#include <iostream>
#include <vector>

using namespace std;

bool DLS(int current, int goal, int limit, vector<vector<int>>& graph, vector<bool>& visited) {

    visited[current] = true;
    cout << "Visiting: " << current << endl;

    if (current == goal)
        return true;

    if (limit <= 0)
        return false;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            if (DLS(neighbor, goal, limit - 1, graph, visited))
                return true;
        }
    }

    return false;
}

void IDDFS(int start, int goal, vector<vector<int>>& graph, int maxDepth) {

    for (int depth = 0; depth <= maxDepth; depth++) {

        vector<bool> visited(graph.size(), false);

        cout << "Depth Limit: " << depth << endl;

        if (DLS(start, goal, depth, graph, visited)) {
            cout << "Goal Found at depth " << depth << endl;
            return;
        }

        cout << endl;
    }

    cout << "Goal Not Found" << endl;
}

int main() {

    int n = 6;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};

    int start = 0;
    int goal = 5;

    IDDFS(start, goal, graph, 5);

    return 0;
}

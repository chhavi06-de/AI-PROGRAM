#include <iostream>
#include <vector>

using namespace std;

void DFS(int current, vector<vector<int>>& graph, vector<bool>& visited, int goal) {

    visited[current] = true;
    cout << "Visiting: " << current << endl;

    if (current == goal) {
        cout << "Goal Found!" << endl;
        return;
    }

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited, goal);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};

    int start = 0;
    int goal = 5;

    vector<bool> visited(n, false);

    DFS(start, graph, visited, goal);

    return 0;
}

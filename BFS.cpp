#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(int start, vector<vector<int>>& graph, int goal) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << "Visiting: " << current << endl;

        
        if (current == goal) {
            cout << "Goal Found!" << endl;
            return;
        }

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
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

    BFS(start, graph, goal);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

void UCS(int start, int goal, vector<vector<pii>>& graph) {

    int n = graph.size();
    vector<int> cost(n, 1e9);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, start});
    cost[start] = 0;

    while (!pq.empty()) {

        int currentCost = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        cout << "Visiting: " << currentNode << " Cost: " << currentCost << endl;

        if (currentNode == goal) {
            cout << "Goal Found with cost " << currentCost << endl;
            return;
        }

        for (auto neighbor : graph[currentNode]) {

            int nextNode = neighbor.first;
            int edgeCost = neighbor.second;

            if (cost[nextNode] > currentCost + edgeCost) {
                cost[nextNode] = currentCost + edgeCost;
                pq.push({cost[nextNode], nextNode});
            }
        }
    }

    cout << "Goal Not Found" << endl;
}

int main() {

    int n = 5;
    vector<vector<pii>> graph(n);

    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({3, 7});
    graph[1].push_back({4, 1});
    graph[2].push_back({4, 3});

    int start = 0;
    int goal = 4;

    UCS(start, goal, graph);

    return 0;
}

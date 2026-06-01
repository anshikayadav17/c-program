#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int source, vector<vector<pii>>& graph) {
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Shortest Distances:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<pii>> graph(n);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[2].push_back({1, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    dijkstra(0, graph);

    return 0;
}

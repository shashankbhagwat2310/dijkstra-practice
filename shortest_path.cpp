#include <bits/stdc++.h>
using namespace std;

int main() {
    // A = 0, B = 1, C = 2, D = 3
    vector<vector<pair<int, int>>> adj(4);

    // Initialize distances and priority queue
    vector<int> dist(4, INT_MAX);

    // Add edges and weights
    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[1].push_back({3, 1});
    adj[3].push_back({1, 1});

    adj[2].push_back({3, 2});
    adj[3].push_back({2, 2});


    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    // Start from A
    dist[0] = 0;
    pq.push({0, 0});

    // Dijkstra's algorithm
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int d = curr.first;
        int u = curr.second;

        if (d != dist[u]) {
            continue;
        }

        // Check all neighbors of the current vertex
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            int newDist = d + weight;

            // Update if a shorter path is found
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances from A
    vector<char> names = {'A', 'B', 'C', 'D'};

    for (int i = 0; i < 4; i++) {
        cout << "Distance from A to "
             << names[i] << " = " << dist[i] << '\n';
    }

    return 0;
}
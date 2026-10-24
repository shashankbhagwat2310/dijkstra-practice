#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 22;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<int> dist(N + 1, INT_MAX);

    // Node 1
    adj[1].push_back({2, 1});
    adj[1].push_back({11, 1});

    // Node 2
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 1});
    adj[2].push_back({21, 1});

    // Node 3
    adj[3].push_back({2, 1});
    adj[3].push_back({4, 1});
    adj[3].push_back({8, 2});

    // Node 4
    adj[4].push_back({3, 1});
    adj[4].push_back({5, 1});

    // Node 5
    adj[5].push_back({4, 1});
    adj[5].push_back({6, 2});
    adj[5].push_back({7, 1});
    adj[5].push_back({22, 1});

    // Node 6
    adj[6].push_back({5, 2});
    adj[6].push_back({7, 2});

    // Node 7
    adj[7].push_back({5, 1});
    adj[7].push_back({6, 2});
    adj[7].push_back({8, 1});

    // Node 8
    adj[8].push_back({3, 2});
    adj[8].push_back({7, 1});
    adj[8].push_back({9, 1});

    // Node 9
    adj[9].push_back({8, 1});
    adj[9].push_back({10, 1});
    adj[9].push_back({19, 2});

    // Node 10
    adj[10].push_back({9, 1});
    adj[10].push_back({11, 1});
    adj[10].push_back({18, 2});

    // Node 11 
    adj[11].push_back({1, 1});
    adj[11].push_back({10, 1});
    adj[11].push_back({12, 2});
    adj[11].push_back({17, 1});

    // Node 12
    adj[12].push_back({11, 2});
    adj[12].push_back({13, 2});

    // Node 13
    adj[13].push_back({12, 2});
    adj[13].push_back({14, 2});
    adj[13].push_back({21, 1});

    // Node 14
    adj[14].push_back({13, 2});
    adj[14].push_back({15, 1});
    adj[14].push_back({16, 1});
    adj[14].push_back({20, 1});

    // Node 15
    adj[15].push_back({14, 1});

    // Node 16
    adj[16].push_back({14, 1});
    adj[16].push_back({17, 2});

    // Node 17
    adj[17].push_back({11, 1});
    adj[17].push_back({16, 2});
    adj[17].push_back({18, 2});

    // Node 18
    adj[18].push_back({10, 2});
    adj[18].push_back({17, 2});
    adj[18].push_back({19, 2});

    // Node 19
    adj[19].push_back({9, 2});
    adj[19].push_back({18, 2});

    // Node 20
    adj[20].push_back({14, 1});
    adj[20].push_back({21, 2});
    adj[20].push_back({22, 1});

    // Node 21
    adj[21].push_back({2, 1});
    adj[21].push_back({13, 1});
    adj[21].push_back({20, 2});
    adj[21].push_back({22, 2});

    // Node 22
    adj[22].push_back({5, 1});
    adj[22].push_back({20, 1});
    adj[22].push_back({21, 2});

    // Dijkstra's algorithm starting from node 1
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int d = curr.first;
        int u = curr.second;

        if (d != dist[u]) {
            continue;
        }

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            int newDist = d + weight;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({dist[v], v});
            }
        }
    }

    // Test: print distances to the required destinations
    vector<int> destinations = {6, 8, 9, 15, 16, 22};

    cout << "Shortest distances from node 1:\n";

    for (int v : destinations) {
        cout << "Distance from node 1 to node "
             << v << " = " << dist[v] << '\n';
    }

    return 0;
}
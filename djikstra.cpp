#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<long long> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int src) {
    // Start with all nodes unreachable except the source.
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated queue entries after a shorter path is found.
        if (d != dist[u]) {
            continue;
        }

        // Relax all outgoing edges from u.
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            long long nd = d + w;

            if (nd < dist[v]) {
                // Update best known distance and push it to the heap.
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}, {2, 4}},
        {{2, 1}, {3, 7}},
        {{4, 3}},
        {{4, 1}},
        {}
    };

    vector<long long> dist = dijkstra(n, adj, 0);

    for (long long d : dist) {
        if (d >= numeric_limits<long long>::max() / 8) {
            cout << "INF ";
        } else {
            cout << d << " ";
        }
    }
    cout << "\n";

    return 0;
}

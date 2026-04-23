#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

using namespace std;

vector<long long> bellmanFord(int n, const vector<tuple<int, int, int>>& edges, int src, bool& hasNegativeCycle) {
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, INF);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (const auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }

    hasNegativeCycle = false;
    for (const auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    return dist;
}

int main() {
    vector<tuple<int, int, int>> edges = {
        {0, 1, 5},
        {0, 2, 4},
        {1, 3, 3},
        {2, 1, 6},
        {3, 2, 2}
    };

    bool hasNegativeCycle = false;
    vector<long long> dist = bellmanFord(4, edges, 0, hasNegativeCycle);

    if (hasNegativeCycle) {
        cout << "Negative cycle\n";
    } else {
        for (long long d : dist) {
            if (d >= numeric_limits<long long>::max() / 8) {
                cout << "INF ";
            } else {
                cout << d << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

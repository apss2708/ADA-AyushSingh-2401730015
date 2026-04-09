def bellman_ford(n, edges, src):
    dist = [float('inf')] * n
    dist[src] = 0
    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            return "Negative cycle"
    return dist

edges = [
    (0, 1, 5),
    (0, 2, 4),
    (1, 3, 3),
    (2, 1, 6),
    (3, 2, 2)
]
print(bellman_ford(4, edges, 0))


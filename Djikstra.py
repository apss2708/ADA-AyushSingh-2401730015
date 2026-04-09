import heapq

def dijkstra(n, adj, src):
    dist = [float('inf')] * n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d != dist[u]:
            continue
        for v, w in adj[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heapq.heappush(pq, (nd, v))
    return dist

n = 5
adj = [
    [(1, 2), (2, 4)],
    [(2, 1), (3, 7)],
    [(4, 3)],
    [(4, 1)],
    []
]
print(dijkstra(n, adj, 0))
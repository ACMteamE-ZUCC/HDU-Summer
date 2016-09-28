//
// Created by andor on 2016/9/10.
//

#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
struct Edge {
    int from, to, dist;
};

struct HeapNode {
    int d, u;

    bool operator<(const HeapNode &rhs) const {
        return d > rhs.d;
    }
};

int pp[maxn], cc;

struct Dijkstra {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int dist) {
        edges.push_back((Edge) {from, to, dist});
        m = edges.size();
        G[from].push_back(m - 1);
    }

    void dijkstra(int s) {
        priority_queue<HeapNode> Q;
        for (int i = 0; i < n; i++) d[i] = INT32_MAX;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode) {0, s});
        while (!Q.empty()) {
            HeapNode x = Q.top();
            Q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (int i = 0; i < (int) G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.dist && d[u] + e.dist <= cc) {
                    d[e.to] = d[u] + e.dist;
                    if (pp[e.to]) d[e.to] = 0;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode) {d[e.to], e.to});
                }
            }
        }

    }
} G, H;


int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> n >> m;
        G.init(n + 1);
        H.init(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G.AddEdge(u, v, 1);
            G.AddEdge(v, u, 1);
        }

    }
    return 0;
}

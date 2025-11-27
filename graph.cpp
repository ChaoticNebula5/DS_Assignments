#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    void dfsUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u])
                dfsUtil(u, visited);
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            cout << v << " ";

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        dfsUtil(start, visited);
        cout << endl;
    }
};

class DSU {
    vector<int> parent, rankv;
public:
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

void KruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);

    int mstCost = 0;

    cout << "\nKruskal MST Edges:\n";

    for (auto &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mstCost += e.w;
            cout << e.u << " -- " << e.v << " == " << e.w << endl;
        }
    }
    cout << "Total MST Cost = " << mstCost << "\n";
}

void PrimMST(int V, vector<vector<pair<int,int>>> &adj) {

    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    int mstCost = 0;

    cout << "\nPrim MST Edges:\n";

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mstCost += weight;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (!inMST[v] && key[v] > w) {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Total MST Cost = " << mstCost << "\n";
}

int main() {

    cout << "Enter number of vertices for BFS/DFS: ";
    int n;
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    int e;
    cin >> e;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nBFS starting from node 0:\n";
    g.BFS(0);

    cout << "DFS starting from node 0:\n";
    g.DFS(0);


    cout << "\nEnter number of vertices for MST: ";
    int V;
    cin >> V;

    cout << "Enter number of weighted edges: ";
    int E;
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    KruskalMST(V, edges);


    vector<vector<pair<int,int>>> adj(V);
    for (auto &e2 : edges) {
        adj[e2.u].push_back({e2.v, e2.w});
        adj[e2.v].push_back({e2.u, e2.w});
    }

    PrimMST(V, adj);

    return 0;
}

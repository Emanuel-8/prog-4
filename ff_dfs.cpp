#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s, t;
ll cap[105][105];
bool vis[105];

ll dfs(int u, ll f) {
    if (u == t) return f;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
        if (!vis[v] && cap[u][v] > 0) {
            ll p = dfs(v, min(f, cap[u][v]));
            if (p > 0) {
                cap[u][v] -= p;
                cap[v][u] += p;
                return p;
            }
        }
    }
    return 0;
}

ll maxflow(int V, vector<array<ll,3>> edges) {
    n = V; s = 0; t = V - 1;
    memset(cap, 0, sizeof cap);
    for (auto e : edges) cap[e[0]][e[1]] += e[2];
    ll flow = 0, f;
    while (memset(vis, 0, sizeof vis), (f = dfs(s, LLONG_MAX)) > 0) flow += f;
    return flow;
}

int main() {
    cout << "FF Killer: " << maxflow(4, {
        {0,1,8}, {0,2,8}, {1,3,8}, {2,3,8}, {2,1,1}
    }) << endl;

    cout << "CP4 Ex 8.5.3.1* (correct): " << maxflow(8, {
        {0,1,1}, {0,2,1}, {0,3,1},
        {1,4,1}, {1,5,1}, {1,6,1}, {2,5,1}, {3,5,1},
        {4,7,1}, {5,7,1}, {6,7,1}
    }) << endl;

    cout << "CS4234 MF Demo: " << maxflow(8, {
        {0,1,10}, {0,2,5}, {0,3,15}, {1,2,4}, {1,4,9},
        {1,5,15}, {2,3,4}, {2,5,8}, {3,6,16}, {4,5,15},
        {4,7,10}, {5,6,15}, {5,7,10}, {6,2,6}, {6,7,10}
    }) << endl;

    cout << "Matching with Capacity: " << maxflow(6, {
        {0,1,1}, {0,2,3}, {1,3,99}, {1,4,99}, {2,4,99},
        {3,5,2}, {4,5,2}
    }) << endl;
}

#include <bits/stdc++.h>
using namespace std;

int n, cap[105][105];   // cap[u][v] = преостанат капацитет (residual)
bool vis[105];

// бара augmenting path со DFS, враќа bottleneck (0 ако нема пат)
int dfs(int u, int t, int f) {
    if (u == t) return f;
    vis[u] = true;
    for (int v = 0; v < n; v++)
        if (!vis[v] && cap[u][v] > 0) {
            int d = dfs(v, t, min(f, cap[u][v]));
            if (d > 0) {
                cap[u][v] -= d;   // напред
                cap[v][u] += d;   // назад (back edge)
                return d;
            }
        }
    return 0;
}

// Ford-Fulkerson: додава проток додека има augmenting path
void fordFulkerson(string ime, int V, vector<array<int,3>> edges) {
    n = V;
    memset(cap, 0, sizeof cap);
    for (auto e : edges) cap[e[0]][e[1]] += e[2];
    int s = 0, t = V - 1;
    int flow = 0, iter = 0, f;
    while (true) {
        memset(vis, 0, sizeof vis);
        f = dfs(s, t, INT_MAX);
        if (f == 0) break;
        flow += f;
        iter++;
    }
    cout << ime << ": max flow = " << flow << " (" << iter << " патеки)\n";
}

int main() {
    // Тест графови од VisuAlgo (s = 0, t = V-1), рабови: {u, v, капацитет}
    fordFulkerson("FF Killer", 4, {
        {0,1,8}, {0,2,8}, {1,3,8}, {2,3,8}, {2,1,1}
    });

    fordFulkerson("CP4 Ex 8.5.3.1* (correct)", 8, {
        {0,1,1}, {0,2,1}, {0,3,1},
        {1,4,1}, {1,5,1}, {1,6,1}, {2,5,1}, {3,5,1},
        {4,7,1}, {5,7,1}, {6,7,1}
    });

    fordFulkerson("CS4234 MF Demo", 8, {
        {0,1,10}, {0,2,5}, {0,3,15}, {1,2,4}, {1,4,9},
        {1,5,15}, {2,3,4}, {2,5,8}, {3,6,16}, {4,5,15},
        {4,7,10}, {5,6,15}, {5,7,10}, {6,2,6}, {6,7,10}
    });

    fordFulkerson("Matching with Capacity", 6, {
        {0,1,1}, {0,2,3}, {1,3,99}, {1,4,99}, {2,4,99},
        {3,5,2}, {4,5,2}
    });
}

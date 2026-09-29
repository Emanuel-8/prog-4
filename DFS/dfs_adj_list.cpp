#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int y : adj[x]) {
        if (!visited[y])
            dfs(y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int start;
    cin >> start;

    dfs(start);
    cout << endl;

    return 0;
}

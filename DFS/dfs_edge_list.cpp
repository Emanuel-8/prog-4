#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int from, to;
};

vector<Edge> edges;
vector<bool> visited;
int n, m;

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < m; i++) {
        int sosed = -1;
        if (edges[i].from == x) sosed = edges[i].to;
        else if (edges[i].to == x) sosed = edges[i].from;

        if (sosed != -1 && !visited[sosed])
            dfs(sosed);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    visited.assign(n, false);

    int start;
    cin >> start;

    dfs(start);
    cout << endl;

    return 0;
}

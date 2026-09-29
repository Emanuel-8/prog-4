#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int from, to;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    int start;
    cin >> start;

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        // mora da se pominat site rabovi za sekoe teme
        for (int i = 0; i < m; i++) {
            int sosed = -1;
            if (edges[i].from == x) sosed = edges[i].to;
            else if (edges[i].to == x) sosed = edges[i].from;

            if (sosed != -1 && !visited[sosed]) {
                visited[sosed] = true;
                q.push(sosed);
            }
        }
    }
    cout << endl;

    return 0;
}

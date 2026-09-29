#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 105;
int mat[MAXN][MAXN];
bool visited[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    int start;
    cin >> start;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < n; i++) {
            if (mat[x][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;

    return 0;
}

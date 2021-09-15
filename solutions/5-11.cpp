#include <bits/stdc++.h>

using namespace std;

int n, m;
int visited[200][200];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int> > q;

void bfs(int start, int end) {
    q.push({start, end});
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] == 0) {
                continue;
            }
            if (visited[nx][ny] == 1) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        } 
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &visited[i][j]);
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][m - 1];
}

#include <bits/stdc++.h>

using namespace std;

int visited[1000][1000];
int n, m;

bool dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }

    if (visited[x][y] == 0) {
        visited[x][y] = 1;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
        return true;
    }

    return false;
}


int main(void) {
    cin >> n >> m;

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &visited[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(i, j)) {
                count++;
            }
        }
    }

    cout << count;
}

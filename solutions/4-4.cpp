#include <bits/stdc++.h>

using namespace std;

#define MAX_DIRECTION 4

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, x, y, direction;
int gameMap[50][50];
int visited[50][50];

void turnLeft() {
    direction = direction == 0 ? 3 : direction - 1;
}

int main(void)
{
    cin >> n >> m;
    cin >> x >> y >> direction;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            gameMap[i][j] = x;
        }
    }

    visited[x][y] = 1;
    
    int cnt = 0;
    int turnCnt = 0;

    while (1) {
        turnLeft();

        int expectX = x + dx[direction];
        int expectY = y + dy[direction];
        
        if (visited[expectX][expectY] == 0 && gameMap[expectX][expectY] == 0) {    
            x = expectX;
            y = expectY;
            visited[x][y] = 1;
            cnt++;
            turnCnt = 0;
            continue;
        }
        
        turnCnt++;
        
        if (turnCnt == MAX_DIRECTION) {
            expectX = x - dx[direction];
            expectY = y - dy[direction];
            if (gameMap[expectX][expectY] == 1) {
                break;
            }
            x = expectX;
            y = expectY;
            turnCnt = 0;
        }
    }

    cout << cnt;
}

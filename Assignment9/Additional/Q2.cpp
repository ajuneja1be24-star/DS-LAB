#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> q;

    if(grid[0][0] == 1) {
        cout << -1;
        return 0;
    }

    dist[0][0] = 0;
    q.push({0,0});

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0) {
                if(dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    if(dist[n-1][m-1] == INT_MAX) cout << -1;
    else cout << dist[n-1][m-1];
}

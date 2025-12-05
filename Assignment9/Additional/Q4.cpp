#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
int n, m;

void dfs(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0') return;
    grid[x][y] = '0';
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    int countIslands = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1') {
                dfs(i, j);
                countIslands++;
            }
        }
    }

    cout << countIslands;
}

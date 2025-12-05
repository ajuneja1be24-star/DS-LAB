#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int nbr : g[node]) {
            if(!vis[nbr]) {
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    vis.assign(n, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int countCC = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            bfs(i);
            countCC++;
        }
    }

    cout << countCC;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> vis(n, 0), ans;
    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int nbr : graph[node]) {
            if(!vis[nbr]) {
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }

    for(int x : ans) cout << x << " ";
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> g(n+1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, k});

    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        int d = t.first;
        int node = t.second;

        if(d != dist[node]) continue;

        for(auto &p : g[node]) {
            int nbr = p.first;
            int w = p.second;
            if(dist[node] + w < dist[nbr]) {
                dist[nbr] = dist[node] + w;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX) {
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
}

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
bool visited[1000]; 
void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
            dfs(neighbor);
    }
}

int main()
{
    char c;
    cout << "DIRECTED OR NOT? Y FOR YES AND N FOR NO: ";
    cin >> c;

    int E, V;
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter number of vertices: ";
    cin >> V;

    adj.resize(V);
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter connected ones: ";
        cin >> u >> v;

        adj[u].push_back(v);
        if (c == 'N')
            adj[v].push_back(u);
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    cout << "\nDFS Traversal: ";
    dfs(src);
    cout << endl;

    return 0;
}

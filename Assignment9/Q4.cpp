#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

int main()
{
    int E, V;
    cout << "ENTER NUMBER OF VERTICES:";
    cin >> V;

    cout << "\nENTER NUMBER OF EDGES:";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    char c;
    cout << "\nDIRECTED OR UNDIRECTED?: Y FOR YES AND N FOR NO:";
    cin >> c;

    cout << "\nENTER CONNECTED EDGES ALONG WITH THE WEIGHTS:";

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        if (c == 'N')
            adj[v].push_back({u, w});
    }

    int distance[1000];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    set<pair<int, int>> s;

    int src;
    cout << "ENTER A SOURCE NODE:";
    cin >> src;

    distance[src] = 0;
    s.insert({0, src});

    while (!s.empty())
    {
        auto it = s.begin();
        int d = it->first;
        int node = it->second;
        s.erase(it);

        for (auto i : adj[node])
        {
            int v = i.first;
            int w = i.second;
            int weight = d + w;

            if (weight < distance[v])
            {
                if (distance[v] != INT_MAX)
                    s.erase({distance[v], v});

                distance[v] = weight;
                s.insert({weight, v});
            }
        }
    }

    cout << "\nTHE FINAL DISTANCES:\n";
    for (int i = 0; i < V; i++)
        cout << distance[i] << " ";

    return 0;
}

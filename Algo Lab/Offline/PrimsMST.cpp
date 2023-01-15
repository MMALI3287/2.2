#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g[n];
    vector<int> dist(n);
    vector<int> parent(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cout << "Enter the source node: ";
    int src, cost = 0;
    cin >> src;
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    set<vector<int>> s;
    dist[src] = 0;
    s.insert({0, src});
    while (!s.empty())
    {
        auto it = *(s.begin());
        s.erase(it);
        int u = it[1];
        int v = parent[it[1]];
        int w = it[0];
        vis[u] = true;
        cost += w;
        for (auto x : g[u])
        {
            if (!vis[x[0]])
            {
                if (dist[x[0]] > x[1])
                {
                    s.erase({dist[x[0]], x[0]});
                    dist[x[0]] = x[1];
                    parent[x[0]] = u;
                    cout << u << " --> " << x[0] << ": " << dist[x[0]] << endl;
                    s.insert({dist[x[0]], x[0]});
                }
            }
        }
    }
    cout << "Cost of MST: " << cost << endl;
    return 0;
}
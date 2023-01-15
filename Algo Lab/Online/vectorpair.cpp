#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cout << "Input the number of vertices: ";
    cin >> n;
    cout << "Input the number of edges: ";
    cin >> e;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= e; i++)
    {
        int u, v, weight;
        cout << "Input the edge and weight: ";
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(v, weight));
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << "-->";
        for (auto edge : adj[i])
        {
            cout << edge.first << "(weight:" << edge.second << ")," << endl;
        }
    }

    return 0;
}
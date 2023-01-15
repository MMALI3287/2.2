#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    return find(parent[x], parent);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (edges[i][0] < edges[j][0])
            {
                swap(edges[i], edges[j]);
            }
        }
    }
    int cost = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][1];
        int v = edges[i][2];
        int w = edges[i][0];
        int x = find(u, parent);
        int y = find(v, parent);
        if (x != y)
        {
            cost += w;
            parent[y] = x;
            s.insert(u);
            s.insert(v);
            cout << u << " --> " << v << ": " << w << endl;
        }
    }
    cout << "Cost of MST: " << cost << endl;
    return 0;
}
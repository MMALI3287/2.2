#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
MMALI @3vdm2r.onmicrosoft.com
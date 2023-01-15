#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, count = 0;
    cout << "Input Node and Edges" << endl;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " --->";
        for (auto i : adj[i])
        {
            cout << i << ", ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == adj[j][i])
            {
                count++;
            }
        }
    }
    cout << "Total loop: " << count << endl;

    return 0;
}
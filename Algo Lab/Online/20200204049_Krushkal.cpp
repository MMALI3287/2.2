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
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({w, u, v});
    }
    int cost = 0;
    for (int i = 0; i < m; i++)
    {
        int u = pq.top()[1];
        int v = pq.top()[2];
        int w = pq.top()[0];
        pq.pop();
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
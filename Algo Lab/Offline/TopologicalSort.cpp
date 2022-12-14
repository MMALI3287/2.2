#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int n, int m)
{
    int count = 0;
    vector<int> indegree(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the edge " << i + 1 << ":";
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topologicalSort;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topologicalSort.push_back(node);
        for (int it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
        count++;
    }
    if (count != n)
    {
        cout << "There is a cycle in the graph" << endl;
    }
    else
    {
        cout << "Topological Sort: ";
        for (int i = 0; i < topologicalSort.size(); i++)
        {
            cout << topologicalSort[i] << " ";
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    topologicalSort(n, m);

    return 0;
}
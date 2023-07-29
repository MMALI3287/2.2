#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
    void printAdj()
    {
        cout << "Adjacency List:" << endl;
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo)
    {
        vis[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour.first])
            {
                dfs(neighbour.first, vis, topo);
            }
        }
        topo.push(node);
    }
    void inputGraph(int e)
    {
        cout << "Enter adjacency list:" << endl;
        int u, v, weight;
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v >> weight;
            addEdge(u, v, weight);
        }
    }
    void getShortestPath(int src, vector<int> &dist, stack<int> &topo, vector<int> &parents)
    {
        dist[src] = 0;
        parents[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            if (dist[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                        parents[i.first] = top;
                    }
                }
            }
        }
    }
    void printPath(int s, int d, vector<int> &parents, vector<int> &dist)
    {
        vector<int> path;
        if (parents[d] == (-1))
        {
            cout << "From " << s << " to " << d << " : ";
            cout << "Cant reach there." << endl;
            return;
        }
        int i = d;
        while (i != s)
        {
            path.push_back(i);
            i = parents[i];
        }
        path.push_back(s);

        reverse(path.begin(), path.end());

        cout << "From " << s << " to " << d << " : ";
        for (auto it : path)
        {
            if (it == s)
            {
                cout << it;
            }
            else
            {
                cout << " -> " << it;
            }
        }

        cout << " and shortest weight : " << dist[d] << endl;

        path.clear();
    }
};

int main()
{
    Graph g;
    cout << "Enter number of nodes:";
    int n;
    cin >> n;
    cout << "Enter the number of edges:";
    int e;
    cin >> e;
    g.inputGraph(e);
    g.printAdj();

    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }
    cout << "Enter source:";
    int source;
    cin >> source;
    vector<int> dist(n);
    vector<int> parents(n, -1);

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    g.getShortestPath(source, dist, s, parents);

    cout << "answer is:" << endl;

    /*for(int i =0; i<dist.size();i++)
    {
        if(dist[i]==INT_MAX)
            cout<<"INF ";
        else
            cout<< dist[i] << " ";
    }*/
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        g.printPath(source, i, parents, dist);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void addEdge(unordered_map<int, list<pair<int, int>>> &adj, int u, int v, int weight)
{
    pair<int, int> p = make_pair(v, weight);
    adj[u].push_back(p);
}

void printAdj(unordered_map<int, list<pair<int, int>>> &adj)
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

void inputGraph(unordered_map<int, list<pair<int, int>>> &adj, int e)
{
    cout << "Enter adjacency list:" << endl;
    int u, v, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> weight;
        addEdge(adj, u, v, weight);
    }
}

void getShortestPath(unordered_map<int, list<pair<int, int>>> &adj, int source, vector<int> &dist, vector<int> &parents)
{
    set<pair<int, int>> st;

    dist[source] = 0;
    parents[source] = source;
    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto neighbour : adj[topNode])
        {
            int newDistance = nodeDistance + neighbour.second;
            if (newDistance < dist[neighbour.first])
            {
                st.erase(make_pair(dist[neighbour.first], neighbour.first));
                dist[neighbour.first] = newDistance;
                parents[neighbour.first] = topNode;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
}

void printPath(int source, int i, vector<int> &dist, vector<int> &parents)
{
    cout << "From " << source << " to " << i << " : ";
    if (parents[i] == -1)
    {
        cout << "Cant reach there." << endl;
        return;
    }
    int j = i;
    cout << j;
    while (j != source)
    {
        j = parents[j];
        cout << " -> " << j;
    }
    cout << " and shortest weight: " << dist[i] << endl;
}

int main()
{
    unordered_map<int, list<pair<int, int>>> adj;
    cout << "Enter number of nodes:";
    int n;
    cin >> n;
    cout << "Enter the number of edges:";
    int e;
    cin >> e;
    inputGraph(adj, e);
    printAdj(adj);
    cout << "Enter source:";
    int source;
    cin >> source;
    vector<int> dist(n);
    vector<int> parents(n, -1);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    getShortestPath(adj, source, dist, parents);
    cout << endl;
    cout << "Shrotest Paths: " << endl;
    for (int i = 0; i < n; i++)
    {
        printPath(source, i, dist, parents);
    }
    cout << endl
         << "HERE" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
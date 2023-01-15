#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, source;
    cout << "Input the number of vertices edges source: ";
    cin >> n >> e >> source;
    vector<list<pair<int, int>>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int v, weight;
        cin >> v >> weight;
        pair<int, int> ed = make_pair(v, weight);
        graph[i].push_back(ed);
    }
    int parent[n];
    int dist[n];
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    parent[source] = source;
    dist[source] = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = INT_MAX, j;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && dist[i] < temp)
            {
                j = i;
                temp = dist[i];
            }
        }
        for (auto edge : graph[i])
        {
            if (dist[edge.first] > dist[i] + edge.second)
            {
                if (visited[edge.first] == 1)
                {
                    cout << "This graph contains negative weight cycle";
                    break;
                }
                dist[edge.first] = dist[i] + edge.second;
                parent[edge.first] = i;
                visited[i] = 0;
            }
        }
    }

    return 0;
}
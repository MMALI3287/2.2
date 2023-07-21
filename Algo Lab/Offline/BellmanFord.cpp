#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, weight;
};

bool bellmanFord(vector<Edge> &edges, vector<int> &dist, vector<int> &parent, int V, int source)
{
    fill(dist.begin(), dist.end(), INF);
    fill(parent.begin(), parent.end(), -1);

    // The distance from the source to itself is 0.
    dist[source] = 0;
    parent[source] = source;

    // Relax each edge V - 1 times.
    for (int v = 0; v < V - 1; v++)
    {
        for (Edge &edge : edges)
        {
            // If the distance to the source from the
            // current vertex is not infinity and adding
            // the edge weight to it results in a smaller
            // distance to the destination vertex, then
            // update the distance to the destination vertex
            // to the new, smaller distance and update the
            // parent of the destination vertex to the
            // current vertex.
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
            }
        }
    }

    // Check for negative-weight cycles.
    for (Edge &edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int E, V, source;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    vector<int> parent(V);
    vector<int> dist(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, weight;
        cout << "Enter the number " << i + 1 << " edge and weight" << endl;
        cout << "u--> ";
        cin >> u;
        cout << "v--> ";
        cin >> v;
        cout << "Weight--> ";
        cin >> weight;
        edges[i] = {u, v, weight};
    }

    cout << "Enter the source" << endl;
    cin >> source;

    if (bellmanFord(edges, dist, parent, V, source))
    {
        for (int i = 0; i < V; i++)
        {
            cout << "From Source " << source << " to node " << i << " : ";
            if (dist[i] == INF)
            {
                cout << "No path found" << endl;
            }
            else
            {
                cout << "Shortest Distance Weight: " << dist[i] << endl;
                cout << "Path: ";
                int j = i;
                while (j != source)
                {
                    cout << j << "<-";
                    j = parent[j];
                }
                cout << source << endl;
            }
        }
    }
    else
    {
        cout << "Negative cycle detected" << endl;
    }

    return 0;
}
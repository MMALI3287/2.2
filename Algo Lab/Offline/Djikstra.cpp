#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u,int v,int weight)
    {
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }
    void printAdj()
    {
        cout<<"Adjacency List:"<<endl;
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
    void inputGraph(int e)
    {
        cout<<"Enter adjacency list:"<<endl;
        int u,v,weight;
        for(int i=0; i<e; i++)
        {
            cin>>u>>v>>weight;
            addEdge(u,v,weight);
        }
    }

    void getShortestPath(int source,vector<int> &dist,vector<int> &parents)
    {
        set<pair<int,int>> st;

        dist[source] = 0;
        parents[source] = source;
        st.insert(make_pair(0,source));
        while(!st.empty())
        {
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;

            st.erase(st.begin());

            for(auto neighbour:adj[topNode])
            {
                if(nodeDistance+neighbour.second < dist[neighbour.first])
                {
                    auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));

                    if(record != st.end())
                    {
                        st.erase(record);
                    }

                    dist[neighbour.first] = nodeDistance+neighbour.second;
                    parents[neighbour.first] = topNode;

                    st.insert(make_pair(dist[neighbour.first],neighbour.first));
                }
            }
        }

    }
    void printPath(int source,int i,vector<int> &dist,vector<int> &parents)
    {
        cout << "From " << source << " to " << i <<" : ";
        if(parents[i]==-1)
        {
            cout<<"Cant reach there."<<endl;
            return;
        }
        int j = i;
        cout<<j;
        while(j!=source)
        {
            j = parents[j];
            cout<<" -> "<<j;

        }
        cout<<" and shortest weight: "<<dist[i]<<endl;
    }
};
int main()
{
    Graph g;
    cout<<"Enter number of nodes:";
    int n;
    cin>>n;
    cout<<"Enter the number of edges:";
    int e;
    cin>>e;
    g.inputGraph(e);
    g.printAdj();
    cout<<"Enter source:";
    int source;
    cin>>source;
    vector<int> dist(n);
    vector<int> parents(n,-1);
    for(int i=0; i<n; i++)
    {
        dist[i] = INT_MAX;
    }
    g.getShortestPath(source,dist,parents);
    cout<<endl;
    cout<<"Shrotest Paths: "<<endl;
    for(int i =0; i<n; i++)
    {
        g.printPath(source,i,dist,parents);
    }
    cout<<endl<<"HERE"<<endl;
    for(int i =0; i<n; i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}


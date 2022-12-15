#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

vector<int> topoSorted;
bool visited[1000] = {false};
vector<int> parents(1000,-1);
vector<long long>cost(1000,INF);

void printPath(int s,int d)
{
    vector<int>path;
    if(parents[d]==(-1))
    {
        cout << "From " << s << " to " << d <<" : ";
        cout << "Cant reach there." << endl;
        return;
    }
    int i = d;
    while(i!=s )
    {
        path.push_back(i);
        i = parents[i];
    }
    path.push_back(s);


    reverse(path.begin(),path.end());


    cout << "From " << s << " to " << d <<" : ";
    for(auto it : path)
    {
        if(it == s)
        {
            cout << it;
        }
        else
        {
            cout << " -> " << it ;
        }

    }

    cout << " and shorted weight : "<< cost[d]<< endl;

    path.clear();
}



void DAG(vector<pair<int,int>> adj[],int v)
{
    for(auto u : adj[v])
    {
        if(cost[u.first] > (cost[v]+u.second))
        {
            cost[u.first] = (cost[v]+u.second);
            parents[u.first] = v;
        }
    }
}


void topoSort(vector<pair<int,int>> adj[],int s)
{
    visited[s] = true;

    for(auto u : adj[s])
    {
        if(!visited[u.first])
            topoSort(adj,u.first);
    }
    topoSorted.push_back(s);

}


void add_edge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back(make_pair(d,w));
}

int main()
{
    int v,e;
    cin >> v>>e;
    int s,d,w;
    vector<pair<int,int>> adj[v+1];
    for(int i =0; i<e; i++)
    {
        cin >> s>>d>>w;
        add_edge(adj,s,d,w);
    }

    topoSort(adj,1);

    reverse(topoSorted.begin(),topoSorted.end());

    int source;
    cin>> source;
    cost[source] =0;
    parents[source] = 0;

    for(auto it : topoSorted)
    {
        DAG(adj,it);
    }


    for(int i =1; i<=v; i++)
    {
        cout << cost[i] << "/" << parents[i] << " " ;
    }

    cout << endl;

    for(int i =1; i<=v; i++)
    {
        printPath(source,i);
    }




    return 0;
}


/*
1 2 2
1 4 4
4 2 1
2 8 5
4 8 3
3 2 3
3 5 2
4 3 3
5 2 4
2 7 3
8 7 4
8 6 1
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pyar;

struct secondDesc
{
    bool operator()(pyar a, pyar b)
    {
        return a.second < b.second;
    }
};

int main()
{
    priority_queue<pyar, vector<pyar>, secondDesc> pq;
    int n, Cost = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cost, weight;
        cin >> cost >> weight;
        pq.push({cost, weight});
    }
    while (!pq.empty())
    {
        cout << "Cost: " << pq.top().first << " Weight: " << pq.top().second << endl;
        Cost += pq.top().first;
        pq.pop();
    }
    cout << "Total Cost: " << Cost << endl;

    return 0;
}
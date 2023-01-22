#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pyar;

struct firstDesc
{
    bool operator()(pyar a, pyar b)
    {
        return a.first > b.first;
    }
};
struct SecondDesc
{
    bool operator()(pyar a, pyar b)
    {
        return a.second > b.second;
    }
};
struct firstAsc
{
    bool operator()(pyar a, pyar b)
    {
        return a.first < b.first;
    }
};
struct SecondAsc
{
    bool operator()(pyar a, pyar b)
    {
        return a.second < b.second;
    }
};

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<pyar, vector<pyar>, SecondAsc> p;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        p.push(make_pair(i, n - i));
    }
    while (!p.empty())
    {
        cout << p.top().first << " " << p.top().second << endl;
        p.pop();
    }

    return 0;
}
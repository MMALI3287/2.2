#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pyar;
struct SecondAsc
{
    bool operator()(pyar a, pyar b)
    {
        return a.second < b.second;
    }
};
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (auto i = v.begin(); i < v.end(); i++)
    {
        cout << *i << " ";
    }
    for (auto i = v.rbegin(); i < v.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << v.size();
    cout << v.capacity();
    cout << v.max_size();
    cout << v.empty();
    cout << v.at(2);
    cout << v.front();
    cout << v.back();
    cout << v.data();
    v.resize(5);
    v.shrink_to_fit();
    v.reserve(4);
    v.clear();
    v.insert(v.begin(), 5);
    v.erase(v.begin());
    v.emplace(v.begin(), 5);
    priority_queue<int> pq;
    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.push(8);
    pq.push(9);
    pq.push(10);
    cout << pq.top();
    pq.pop();
    cout << pq.top();
    pq.size();
    pq.empty();
    priority_queue<vector<pair<int, int>>, vector<vector<pair<int, int>>>, greater<vector<pair<int, int>>>> pq1;
    pq1.push({{1, 2}, {3, 4}});
    pq1.push({{5, 6}, {7, 8}});
    pq1.push({{9, 10}, {11, 12}});
    pq1.push({{13, 14}, {15, 16}});
    cout << pq1.top().begin()->first;
    pq1.pop();
    cout << pq1.top().begin()->first;
    pq1.size();
    pq1.empty();
    pq1.swap(pq1);
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
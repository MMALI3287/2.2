#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        int row;
        int col;
        cin >> row;
        cin >> col;
        p.push_back(make_pair(row, col));
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << p[i].first << " " << p[i].second << endl;
    // }
    vector<int> v;
    v.push_back(p[0].first);
    for (int i = 0; i < n; i++)
    {
        v.push_back(p[i].second);
    }
    for (int i = 0; i < n + 1; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
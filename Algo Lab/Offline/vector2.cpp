#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "hello" << endl;

    vector<int> v;
    vector<int>::iterator i;
    vector<int>::reverse_iterator ri;

    for (int i = 0; i < 20; i++)
    {
        v.push_back(i + 1);
    }

    i = v.begin();
    v.erase(i + 4);
    v.insert(i + 4, 100);
    for (i = v.begin(); i != v.end(); i++)
    {
        cout << *i << "  ";
    }
    cout << endl;
    for (i = v.end() - 1; i != v.begin() - 1; i--)
    {
        cout << *i << "  ";
    }
    cout << endl;
    for (ri = v.rbegin(); ri != v.rend(); ri++)
    {
        cout << *ri << "  ";
    }
    cout << endl;
    for (int j : v)
    {
        cout << j << "  ";
    }
    return 0;
}
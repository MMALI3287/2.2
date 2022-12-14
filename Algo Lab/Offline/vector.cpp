#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "hello" << endl;
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i + 1);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
    cout << "Max Size: " << v.max_size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << !v.empty() << endl;
    v.resize(10);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
    v.shrink_to_fit();
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;

    return 0;
}
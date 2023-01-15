#include <bits/stdc++.h>
using namespace std;

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}
int main()
{
    stack<int> st;
    stack<int> st2;
    queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        st.push(i + 1);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st2.push(st.top());
        q.push(st.top());
        st.pop();
    }
    cout << endl;
    print(st2);
    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
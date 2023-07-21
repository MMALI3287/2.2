#include <iostream>
#include <vector>

using namespace std;

void sumOfSubsets(int s, int k, int r, vector<int> &x, vector<int> &w, int m)
{
    if (s == m)
    {
        for (int i = 1; i <= k; i++)
        {
            int temp = w[x[i] - 1];
            if (temp <= m)
            {
                cout << temp << " ";
            }
        }
        cout << endl;
    }
    else if (s + w[k] <= m && s + r >= m)
    {
        x[k + 1] = k + 1;
        sumOfSubsets(s + w[k], k + 1, r - w[k], x, w, m);
    }

    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {
        x[k + 1] = 0;
        sumOfSubsets(s, k + 1, r - w[k], x, w, m);
    }
}

int main()
{
    vector<int> w = {1, 2, 3, 4, 5};
    int m = 7;
    int n = w.size();
    vector<int> x(n + 1);
    int r = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        r += w[i];
    }
    sumOfSubsets(0, 0, r, x, w, m);
    return 0;
}

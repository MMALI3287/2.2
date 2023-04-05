#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    int W;
    cout << "Input the total weight" << endl;
    cin >> W;
    int n;
    cin >> n;
    cout << "Input total number of items" << endl;
    int val[n];
    int wt[n];
    cout << "Input profit and weight of the items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        cin >> wt[i];
    }

    cout
        << "Maximum value that can be put in a knapsack of capacity " << W << " is " << knapSack(W, wt, val, n) << endl;
    return 0;
}

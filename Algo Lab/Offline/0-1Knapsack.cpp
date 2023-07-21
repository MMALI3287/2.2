#include <bits/stdc++.h>
using namespace std;

// knapsack function
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            // Base case
            if (i == 0 || w == 0)
                K[i][w] = 0;

            // If wt[i-1] is greater than W, then
            // this item cannot be included in the
            // optimal solution
            else if (wt[i - 1] <= w)

                // Return the maximum of two cases:
                // (1) nth item included
                // (2) not included
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);

            // If wt[i-1] is greater than W, then
            // this item cannot be included in the
            // optimal solution
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

// main function
int main()
{
    int W;
    cin >> W;
    int n;
    cin >> n;
    int val[n];
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        cin >> wt[i];
    }

    cout
        << knapsack(W, wt, val, n) << endl;
    return 0;
}
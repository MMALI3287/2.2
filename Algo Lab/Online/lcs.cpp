#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B, string &lcs1, string &lcs2, string &lcs3)
{
    int m = A.length();
    int n = B.length();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            lcs1 = A[i - 1] + lcs1;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    i = m, j = n;
    while (dp[i][j] == dp[i - 1][j])
    {
        i--;
    }
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            lcs2 = A[i - 1] + lcs2;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    // i = m, j = n;
    // while (dp[i][j] == dp[i][j - 1])
    // {
    //     j--;
    // }
    // while (i > 0 && j > 0)
    // {
    //     if (A[i - 1] == B[j - 1])
    //     {
    //         lcs3 = A[i - 1] + lcs3;
    //         i--;
    //         j--;
    //     }
    //     else if (dp[i - 1][j] > dp[i][j - 1])
    //         i--;
    //     else
    //         j--;
    // }

    return dp[m][n];
}

int main()
{
    string A, B, lcs1, lcs2, lcs3;

    cout << "Enter the first word: ";
    cin >> A;
    cout << "Enter the second word: ";
    cin >> B;

    cout << "Length of the LCS: " << endl
         << LCS(A, B, lcs1, lcs2, lcs3) << endl;
    cout << "LCS1: " << lcs1 << endl;
    cout << "LCS2: " << lcs2 << endl;
    // cout << "LCS3: " << lcs3 << endl;

    return 0;
}

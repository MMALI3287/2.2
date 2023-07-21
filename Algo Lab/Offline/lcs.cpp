#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B, string &lcs)
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

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            lcs = A[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return dp[m][n];
}

int main()
{
    string A, B, lcs;

    cout << "Enter the first word: ";
    cin >> A;
    cout << "Enter the second word: ";
    cin >> B;

    cout << "Length of the LCS: " << LCS(A, B, lcs) << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}

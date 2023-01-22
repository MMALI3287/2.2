#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q[4][5], A[4];
    //  = {(3, 1, 2, 1), (1, 5, 2, 1), (1, 2, 6, 1), (1, 1, 1, 4)};
    //  = {(18), (17), (31), (19)};
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> Q[i][j];
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = i + 1; j <= 4; j++)
        {
            int ratio = Q[j][i] / Q[i][i];
            for (int k = 1; k <= 5; k++)
            {
                Q[j][k] = Q[j][k] - ratio * Q[i][k];
            }
        }
    }
    for (int i = 3; i >= 1; i--)
    {
        A[i] = Q[i][5];
        for (int j = i + 1; j <= 5; j++)
        {
            A[i] = A[i] - Q[i][j] * A[j];
        }
        A[i] = A[i] / Q[i][i];
    }
    cout << "Printing output..." << endl;
    for (int i = 1; i <= 4; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
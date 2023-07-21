#include <bits/stdc++.h>
using namespace std;
int board[100];
int sol = 0;
bool canPlace(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (abs(board[j] - i) == abs(j - k) || board[j] == i)
        {
            return false;
        }
    }
    return true;
}
void n_queens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (canPlace(k, i))
        {
            board[k] = i;
            if (k == n)
            {
                sol++;
                cout << "Solution " << sol << ": ";
                for (int i = 1; i <= n; i++)
                    cout << board[i] << " ";
                cout << endl;
            }
            else
                n_queens(k + 1, n);
        }
    }
}
int main()
{
    memset(board, 0, sizeof(board));
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    n_queens(1, n);
    return 0;
}
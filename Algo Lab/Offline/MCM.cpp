#include <bits/stdc++.h>
using namespace std;

int mcm(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (temp < min)
            min = temp;
    }
    return min;
}

int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int arr[n + 1], s[n + 1][n + 1], p[n + 1][n + 1];
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i <= n; i++)
        cin >> arr[i];
    cout << "Minimum number of multiplications is " << mcm(arr, 1, n);
    return 0;
}
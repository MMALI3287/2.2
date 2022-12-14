#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    //! New (Insertion sort part)
    for (int i = 1; i < n1; i++)
    {
        int current = L[i];
        int j = i - 1;
        while (j >= 0 && L[j] > current)
            L[j + 1] = L[j--];
        L[j + 1] = current;
    }
    for (int i = 1; i < n2; i++)
    {
        int current = R[i];
        int j = i - 1;
        while (j >= 0 && R[j] > current)
            R[j + 1] = R[j--];
        R[j + 1] = current;
    }
    //!
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergesort(int arr[], int l, int r)
{
    if (r - l >= 3) //! New
    {
        int m = (r + l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n = 16;
    int arr[n] = {23, 12, 9, 24, 8, 21, 28, 94, 87, 37, 73, 92, 71, 96, 80, 16};
    int low = 0, high = n - 1;
    mergesort(arr, low, high);
    cout << "Ascending order Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
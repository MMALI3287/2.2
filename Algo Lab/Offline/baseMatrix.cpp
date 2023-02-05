#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rowColumnReduction(vector<vector<int>> matrix, int n, int u, int v)
{
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            int temp = matrix[i][j];
            if (temp < min)
            {
                min = temp;
            }
        }
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = matrix[i][j] - min;
        }
    }
    for (int j = 0; j < n; j++)
    {
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int temp = matrix[i][j];
            if (temp < min)
            {
                min = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            matrix[i][j] = matrix[i][j] - min;
        }
    }
    return matrix;
}

int main()
{
    int n = 5, baseCost = 0;
    vector<vector<int>> matrix;
    matrix.push_back({INT_MAX, 20, 30, 10, 11});
    matrix.push_back({15, INT_MAX, 16, 04, 02});
    matrix.push_back({03, 05, INT_MAX, 02, 04});
    matrix.push_back({19, 06, 18, INT_MAX, 03});
    matrix.push_back({16, 04, 07, 16, INT_MAX});
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
        for (int j = 0; j < n; j++)
            matrix[i][j] -= min;
        baseCost += min;
    }
    for (int j = 0; j < n; j++)
    {
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int temp = matrix[i][j];
            if (temp < min)
            {
                min = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            matrix[i][j] = matrix[i][j] - min;
        }
        baseCost = baseCost + min;
    }
    cout << "Base Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "Base Cost: " << baseCost << endl;
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, greater<pair<int, vector<vector<int>>>>> tsp;
    while (!tsp.empty())
    {
        pair<int, vector<vector<int>>> temp = tsp.top();
        tsp.pop();
        int cost = temp.first;
        vector<vector<int>> matrix = temp.second;
        if (cost > baseCost)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    vector<vector<int>> tempMatrix = matrix;
                    tempMatrix[i][j] = INT_MAX;
                    tempMatrix = rowColumnReduction(tempMatrix, n, i, j);
                    int tempCost = 0;
                    for (int i = 0; i < n; i++)
                    {
                        int min = INT_MAX;
                        for (int j = 0; j < n; j++)
                        {
                            if (tempMatrix[i][j] < min)
                                min = tempMatrix[i][j];
                        }
                        for (int j = 0; j < n; j++)
                            tempMatrix[i][j] -= min;
                        tempCost += min;
                    }
                    for (int j = 0; j < n; j++)
                    {
                        int min = INT_MAX;
                        for (int i = 0; i < n; i++)
                        {
                            int temp = tempMatrix[i][j];
                            if (temp < min)
                            {
                                min = temp;
                            }
                        }
                        for (int i = 0; i < n; i++)
                        {
                            tempMatrix[i][j] = tempMatrix[i][j] - min;
                        }
                        tempCost = tempCost + min;
                    }
                    tempCost += cost;
                    tsp.push({tempCost, tempMatrix});
                }
            }
        }
    }

    return 0;
}
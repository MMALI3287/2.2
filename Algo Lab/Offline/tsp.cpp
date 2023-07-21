#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<pair<pair<int, vector<vector<int>>>, vector<int>>, vector<pair<pair<int, vector<vector<int>>>, vector<int>>>, greater<pair<pair<int, vector<vector<int>>>, vector<int>>>> tsp;

pair<int, vector<vector<int>>> rowColumnReduction(vector<vector<int>> matrix, int cost)
{
    for (int i = 0; i < n; i++)
    {
        int rowMin = INT_MAX;
        for (int j = 0; j < n; j++)
            rowMin = min(matrix[i][j], rowMin);
        if (rowMin < 999)
        {
            cost += rowMin;
            for (int j = 0; j < n; j++)
                matrix[i][j] -= rowMin;
        }
    }
    for (int j = 0; j < n; j++)
    {
        int colMin = INT_MAX;
        for (int i = 0; i < n; i++)
            colMin = min(matrix[i][j], colMin);
        if (colMin < 999)
        {
            cost += colMin;
            for (int i = 0; i < n; i++)
                matrix[i][j] -= colMin;
        }
    }
    return make_pair(cost, matrix);
}

bool contains(vector<int> path, int key)
{
    for (int i = 0; i < path.size(); i++)
        if (path[i] == key)
            return true;
    return false;
}

pair<pair<int, vector<vector<int>>>, vector<int>> traverse(vector<vector<int>> matrix, int u, int v, int cost, int source, vector<int> path)
{
    cost += matrix[u][v];
    for (int i = 0; i < n; i++)
        matrix[u][i] = matrix[i][v] = INT_MAX;
    matrix[v][source] = INT_MAX;
    path.push_back(v);
    return make_pair(rowColumnReduction(matrix, cost), path);
}

pair<pair<int, vector<vector<int>>>, vector<int>> findTSPSolution(vector<vector<int>> matrix, int source)
{
    vector<int> path;
    path.push_back(source);
    tsp.push(make_pair(make_pair(0, matrix), path));
    while (!tsp.empty())
    {
        pair<pair<int, vector<vector<int>>>, vector<int>> curr = tsp.top();
        tsp.pop();
        for (int v = 0; v < n; v++)
            if (!contains(curr.second, v))
            {
                auto tem = traverse(curr.first.second, curr.second[curr.second.size() - 1], v, curr.first.first, source, curr.second);
                if (tem.first.first < 999 && tem.first.first > 0)
                    tsp.push(tem);
            }
        if (tsp.top().second.size() == n)
            break;
    }
    return tsp.top();
}

int main()
{
    int source;
    cout << "Enter source and number of nodes: ";
    cin >> source >> n;
    cout << "Enter matrix: " << endl;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    auto result = findTSPSolution(matrix, source);
    cout << "Final Cost:" << result.first.first << endl
         << "Final Path:";
    for (int i = 0; i < result.second.size(); i++)
        cout << result.second[i] << " -> ";
    cout << source << endl;
    return 0;
}
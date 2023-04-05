#include <bits/stdc++.h>
using namespace std;
int n = 4;
priority_queue<pair<pair<int, vector<vector<int>>>, vector<int>>, vector<pair<pair<int, vector<vector<int>>>, vector<int>>>, greater<pair<pair<int, vector<vector<int>>>, vector<int>>>> tsp;
bool contains(vector<int> path, int key)
{
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == key)
            return true;
    }
    return false;
}

pair<int, vector<vector<int>>> rowColumnReduction(vector<vector<int>> matrix, int cost)
{
    for (int i = 0; i < n; i++)
    {
        int rowMin = INT_MAX;
        int colMin = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < rowMin)
                rowMin = matrix[i][j];
            if (matrix[j][i] < colMin)
                colMin = matrix[j][i];
        }
        if (rowMin < 999)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] -= rowMin;
            cost += rowMin;
        }
        cout << "cost: " << cost << endl;
        if (colMin < 999)
        {
            for (int j = 0; j < n; j++)
                matrix[j][i] -= colMin;
            cost += colMin;
        }
        cout << "cost: " << cost << endl;
    }
    return make_pair(cost, matrix);
}
pair<pair<int, vector<vector<int>>>, vector<int>> traverse(vector<vector<int>> matrix, int u, int v, int cost, int source, vector<int> path)
{
    cost += matrix[u][v];
    for (int i = 0; i < n; i++)
    {
        matrix[u][i] = matrix[i][v] = INT_MAX;
    }
    matrix[v][source] = INT_MAX;
    path.push_back(v);
    return make_pair(rowColumnReduction(matrix, cost), path);
}

int main()
{
    int baseCost = 0;
    vector<vector<int>> matrix;
    vector<int> path;
    matrix.push_back({INT_MAX, 20, 30, 10, 11});
    matrix.push_back({15, INT_MAX, 16, 04, 02});
    matrix.push_back({03, 05, INT_MAX, 02, 04});
    matrix.push_back({19, 06, 18, INT_MAX, 03});
    matrix.push_back({16, 04, 07, 16, INT_MAX});
    // matrix.push_back({INT_MAX, 4, 12, 7});
    // matrix.push_back({5, INT_MAX, INT_MAX, 18});
    // matrix.push_back({11, INT_MAX, INT_MAX, 6});
    // matrix.push_back({10, 2, 3, INT_MAX});
    pair<int, vector<vector<int>>> baseMatrix = rowColumnReduction(matrix, baseCost);
    cout << "Base Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << baseMatrix.second[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "Base Cost: " << baseMatrix.first << endl;
    cout << "Enter the source node: ";
    int source;
    cin >> source;
    path.push_back(source);
    for (int i = 0; i < n; i++)
    {
        if (i == source)
            continue;
        cout << "Traversing from " << source << " to " << i << endl;
        pair<pair<int, vector<vector<int>>>, vector<int>> temp = traverse(baseMatrix.second, source, i, baseMatrix.first, source, path);
        tsp.push(temp);
        cout << "Cost: " << temp.first.first << endl;
        cout << "Path: ";
        for (int i = 0; i < temp.second.size(); i++)
            cout << temp.second[i] << " < ";
        cout << endl;
    }
    while (tsp.empty() == false)
    {
        pair<pair<int, vector<vector<int>>>, vector<int>> temp = tsp.top();
        tsp.pop();
        int cost = temp.first.first;
        vector<vector<int>> matrx = temp.first.second;
        vector<int> path = temp.second;
        int v = path[path.size() - 1];
        for (int i = 0; i < n; i++)
        {
            if (contains(path, i))
                continue;
            cout << "Traversing from " << v << " to " << i << endl;
            pair<pair<int, vector<vector<int>>>, vector<int>> temp = traverse(matrx, v, i, cost, source, path);
            tsp.push(temp);
            cout << "Cost: " << temp.first.first << endl;
            cout << "Path: ";
            for (int i = 0; i < temp.second.size(); i++)
                cout << temp.second[i] << " < ";
            cout << endl;
            if (temp.second.size() == n)
            {
                cout << "Final Cost: " << temp.first.first << endl;
                cout << "Final Path: ";
                for (int i = 0; i < temp.second.size(); i++)
                    cout << temp.second[i] << " < ";
                cout << source;
                cout << endl;
                break;
            }
        }
        if (path.size() == n)
            break;
    }

    return 0;
}
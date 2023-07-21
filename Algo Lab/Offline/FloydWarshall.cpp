#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class FloydWarshall
{
private:
    int n;
    vector<vector<double>> d;
    vector<vector<int>> pi;

public:
    FloydWarshall(vector<vector<double>> matrix)
    {
        n = matrix.size();
        d = vector<vector<double>>(n, vector<double>(n));
        pi = vector<vector<int>>(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] != INT_MAX)
                    pi[i][j] = j;
                d[i][j] = matrix[i][j];
            }
        }
    }

    vector<vector<double>> getApspMatrix()
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (d[i][k] + d[k][j] < d[i][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        pi[i][j] = pi[i][k];
                    }
                }
            }
        }
        return d;
    }

    vector<int> reconstructShortestPath(int start, int end)
    {
        vector<int> path;
        if (d[start][end] == INT_MAX)
            return path;
        int at = start;
        for (; at != end; at = pi[at][end])
        {
            path.push_back(at);
        }
        path.push_back(end);
        return path;
    }

    static vector<vector<double>> createGraph(int n)
    {
        vector<vector<double>> matrix(n, vector<double>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            matrix[i][i] = 0;
        }
        return matrix;
    }
};

int main()
{
    int n = 5;
    vector<vector<double>> m = FloydWarshall::createGraph(n);

    m[0][1] = 1;
    m[0][2] = 1;
    m[1][2] = 3;
    m[1][4] = 5;
    m[2][1] = 2;
    m[2][4] = 4;
    m[3][2] = 1;
    m[4][3] = 2;

    FloydWarshall solver(m);
    vector<vector<double>> dist = solver.getApspMatrix();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Shortest path: %d to %d is %.3f\n", i, j, dist[i][j]);
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<int> path = solver.reconstructShortestPath(i, j);
            string str = "";
            if (path.size() == 0)
            {
                str = "Path Does Not Exist";
            }
            else
            {
                str = to_string(path[0]);
                for (int k = 1; k < path.size(); k++)
                {
                    str += " -> " + to_string(path[k]);
                }
            }

            printf("Shortest path %d to %d is:[ %s ]\n", i, j, str.c_str());
        }
    }

    return 0;
}
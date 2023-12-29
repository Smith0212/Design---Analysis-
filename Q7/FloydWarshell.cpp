#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshall(int n, vector<vector<int>> &dist)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] =min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    cout << "Enter the source vertex, destination vertex, and weight of each edge:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u - 1][v - 1] = w;
    }

    floydWarshall(n, dist);

    cout << "Shortest Distance Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

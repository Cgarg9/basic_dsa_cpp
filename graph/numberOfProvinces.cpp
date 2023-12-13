// https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void dfs(vector<int> adjList[], vector<int> &visited, int node)
{
    visited[node] = 1;
    for (auto it : adjList[node])
    {
        if (visited[it] != 1)
        {
            dfs(adjList, visited, it);
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adjMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }
    // create adjList
    vector<int> adjList[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    vector<int> visited(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            dfs(adjList, visited, i);
        }
    }
    cout << count << endl;
    return 0;
}

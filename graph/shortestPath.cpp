// using dijkstra's algo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void dijkstra(vector<pair<int, int>> adjList[], vector<int> &dist, int src, vector<int> &parent)
{
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // weight, vertex
    pq.push({0, src});
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (auto node : adjList[u])
        {
            int v = node.first;
            int edgeWeight = node.second;
            if (dist[v] > wt + edgeWeight)
            {
                dist[v] = wt + edgeWeight;
                pq.push({wt + edgeWeight, v});
                parent[v] = u;
            }
        }
    }
}
int main()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<pair<int, int>> adjList[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        // adjList[v].push_back({u, w});
    }
    vector<int> dist(n, INT_MAX), parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    dijkstra(adjList, dist, src, parent);
    vector<int> path;
    // for (int i = 0; i < dist.size(); i++)
    // {
    //     cout << dist[i] << endl;
    // }
    // destination is last node;
    if (dist[n - 1] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        int node = n - 1;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
    return 0;
}

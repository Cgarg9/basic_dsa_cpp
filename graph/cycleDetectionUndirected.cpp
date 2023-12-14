BFS

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool isCycle(int node, vector<int> adj[], vector<int> &visited, vector<int> &parent)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (auto adjNode: adj[temp])
        {
            if (visited[adjNode] != 1)
            {
                q.push(adjNode);
                parent[adjNode] = temp;
                visited[adjNode] = 1;
            }
            else if (visited[adjNode] == 1 && parent[adjNode] != temp)
            {
                return true;
            }
        }
    }
    return false;
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
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            cout << isCycle(i, adjList, visited, parent) << endl;
        }
    }
    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------
DFS

class Solution {
private:
    bool isCyclic(int v, int parent, unordered_map<int, bool>& visited, vector<int> adj[]) {
        visited[v] = true;
        for (auto neighbour : adj[v]) {
            if (!visited[neighbour]) {
                bool ans = isCyclic(neighbour, v, visited, adj);
                if (ans) {
                    return true;
                }
            }
            else if (neighbour != parent) {
                return true;
            }
        }
        return false;
  }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // to handle all componenets
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bool ans = isCyclic(i, -1, visited, adj);
                if (ans == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

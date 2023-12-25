// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

class DSU {
    vector<int> rank, parent;
    public:
        DSU(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
        int findParent(int node) {
            if (node == parent[node]) {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        void unionByRank(int u, int v) {
            int parentU = findParent(u);
            int parentV = findParent(v);

            // same component
            if (parentU == parentV) return;
            // different components
            if (rank[parentU] < rank[parentV]) {
                parent[parentU] = parentV;
            }
            else if (rank[parentU] > rank[parentV]) {
                parent[parentV] = parentU;
            }
            else {
                parent[parentV] = parentU;
                rank[parentU] += 1;
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>>edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                edges.push_back({it[1], {i, it[0]}});
            }
        }
        DSU ds(V);
        sort(edges.begin(), edges.end());
        int minWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (ds.findParent(u) != ds.findParent(v)) {
                minWt += wt;
                ds.unionByRank(u, v);
            }
        }
        return minWt;
    }
};

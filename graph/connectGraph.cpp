// https://www.geeksforgeeks.org/problems/connecting-the-graph/1

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
        int components() {
            int cnt = 0;
            for (int i = 0; i < parent.size()-1; i++) {
                if (parent[i] == i) {
                    cnt++;
                }
            }
            return cnt;
        }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DSU ds(n);
        int extraEdges = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                extraEdges++;
            }
            else {
                ds.unionByRank(u, v);
            }
        }
        int components = ds.components();
        // cout << components << extraEdges;
        int ans = components - 1;
        if (extraEdges >= ans) {
            return ans;
        }
        return -1;
    }
};


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
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
int main()
{

    return 0;
}

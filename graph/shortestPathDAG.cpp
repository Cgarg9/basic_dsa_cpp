// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
    private:
        void topoSort(vector<pair<int, int>> adjList[], int node, vector<int>& vis, stack<int>& st) {
            vis[node] = 1;
            for (auto it : adjList[node]) {
                int v = it.first;
                if (vis[v] == -1) {
                    topoSort(adjList, v, vis, st);
                }
            }
            st.push(node);
        }
    public:
        vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
            vector<pair<int, int>> adjList[N];
            for (int i = 0; i < M; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                adjList[u].push_back({v, wt});
            }
            
            vector<int> vis(N, -1);
            stack<int> st;
            for (int i = 0; i < N; i++) {
                if (vis[i] == -1) {
                    topoSort(adjList, i, vis, st);
                }
            }
            // initialise distance vector with INT_MAX;
            vector<int> dist(N, INT_MAX);
            // set src dist as 0;
            dist[0] = 0;
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                for (auto it : adjList[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
            return dist;
        }

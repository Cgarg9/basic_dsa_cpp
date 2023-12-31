// Kosaraju's Algorithm
// do dfs and store nodes in a stack after returning from the call
// reverse adjacency list
// again do a dfs by using top of stack
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
    private:
    void dfs(int node, vector<vector<int>> adj, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                dfs(it, adj, visited, st);
            }
        }
        st.push(node);
    }
    void depthFirstSearch(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                depthFirstSearch(it, adj, visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        
        stack<int> st;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, st);
            }
        }
        vector<vector<int>> adjR(V);
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            for (auto &it : adj[i]) {
                // i -> it
                // it -> i
                adjR[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (visited[node] == 0) {
                scc++;
                depthFirstSearch(node, adjR, visited);
            }
        }
        return scc;
    }
};

//  https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto adjNode : graph[node]) {
                if (color[adjNode] == -1) {
                    q.push(adjNode);
                    color[adjNode] = !color[node];
                }
                else if (color[adjNode] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (check(i, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

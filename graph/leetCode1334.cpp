// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        int maxCount = INT_MAX;
        int index = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= d) {
                    cnt++;
                }
            }
            if(cnt <= maxCount) {
                maxCount = cnt;
                index = i;
            }
        }
        return index;
    }
};

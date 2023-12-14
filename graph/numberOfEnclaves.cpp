// https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& copy) {
        
        if (row < 0 || row >= copy.size() || col < 0 || col >= copy[0].size()) return; 

        if (copy[row][col] == 0) {
            return;
        }
        copy[row][col] = 0;

        dfs(row+1, col, copy);
        dfs(row-1, col, copy);
        dfs(row, col+1, copy);
        dfs(row, col-1, copy);

        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> copy(n, vector<int>(m, 0));
        copy = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if( i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if (copy[i][j] == 1)
                    dfs(i, j, copy);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (copy[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

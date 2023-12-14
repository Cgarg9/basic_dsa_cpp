// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        // row column time
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
                else if (grid[i][j] == 1) {
                    freshOranges += 1;
                }
            }
        }
        int time = 0;
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        while (!q.empty()) {
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();

            time = max(time, tm);
            for(int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 
                    && visited[x][y] != 1) {
                        q.push({{x, y}, tm+1});
                        visited[x][y] = 1;
                        freshOranges--;
                    }
            }
        }
        if (freshOranges != 0) {
            return -1;
        }
        return time;
    }
};

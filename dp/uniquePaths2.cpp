// https://leetcode.com/problems/unique-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
private:
    int helpMemo(vector<vector<int>>& o, int row, int col, vector<vector<int>>& dp) {
        if (row < 0 || row >= o.size() || col < 0 || col >= o[0].size() || o[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;

        if (dp[row][col] != -1) return dp[row][col];

        int left = helpMemo(o, row, col-1, dp);
        int top = helpMemo(o, row-1, col, dp);

        return dp[row][col] = top + left;
    }
    int helpTabulation(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (o[i][j] == 1) dp[i][j] = 0;
                else if (i == 0 || j == 0) dp[i][j] = 1;
                else {
                    int left = dp[i][j-1];
                    int top = dp[i-1][j];
                    dp[i][j] = left + top;
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return helpTabulation(o);
    }
};

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }
    Solution obj;
    cout << obj.uniquePathsWithObstacles(grid) << endl;
    return 0;
}
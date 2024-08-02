// https://leetcode.com/problems/unique-paths/description/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution
{
private:
    int helpRecursive(int n, int m, int row, int col)
    {
        if (row < 0 || col < 0 || row >= n || col >= m)
            return 0;
        if (row == 0 && col == 0)
            return 1;

        int left = helpRecursive(n, m, row, col - 1);
        int top = helpRecursive(n, m, row - 1, col);

        return top + left;
    }
    int helpMemo(int n, int m, int row, int col, vector<vector<int>> &dp)
    {
        if (row < 0 || col < 0 || row >= n || col >= m)
            return 0;
        if (row == 0 && col == 0)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        int left = helpMemo(n, m, row, col - 1, dp);
        int top = helpMemo(n, m, row - 1, col, dp);

        return dp[row][col] = top + left;
    }
    int helpTabulation(int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // base case
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        for (int i = 0; i < m; i++)
            dp[0][i] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                int left = dp[i][j - 1];
                int top = dp[i - 1][j];
                dp[i][j] = top + left;
            }
        }
        return dp[n - 1][m - 1];
    }

public:
    int uniquePaths(int n, int m)
    {
        // return helpRecursive(n, m, n-1, m-1);

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return helpMemo(n, m, n-1, m-1, dp);

        // return helpTabulation(n, m);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Solution obj;
    cout << obj.uniquePaths(n, m);
    return 0;
}
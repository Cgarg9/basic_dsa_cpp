// https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution
{
private:
    int helpRecursive(int n, int m, vector<vector<int>> &matrix)
    {
        if (n < 0 || m < 0 || m >= matrix[0].size() || n >= matrix.size())
            return INT_MAX;

        if (n == 0 && m == 0)
            return matrix[n][m];

        int left = helpRecursive(n, m - 1, matrix);
        int top = helpRecursive(n - 1, m, matrix);

        return matrix[n][m] + min(left, top);
    }
    int helpMemo(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (n < 0 || m < 0 || m >= matrix[0].size() || n >= matrix.size())
            return INT_MAX;

        if (n == 0 && m == 0)
            return matrix[n][m];
        if (dp[n][m] != -1)
            return dp[n][m];

        int left = helpMemo(n, m - 1, matrix, dp);
        int top = helpMemo(n - 1, m, matrix, dp);

        return dp[n][m] = matrix[n][m] + min(left, top);
    }
    int helpTabulation(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = matrix[i][0] + dp[i - 1][0];
        }
        for (int i = 1; i < m; i++)
        {
            dp[0][i] = matrix[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }

public:
    int minPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // return helpRecursive(n-1, m-1, matrix);

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return helpMemo(n - 1, m - 1, matrix, dp);

        return helpTabulation(matrix);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }
    Solution obj;
    cout << obj.minPathSum(matrix);
    return 0;
}
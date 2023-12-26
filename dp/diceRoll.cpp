// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/?envType=daily-question&envId=2023-12-26

class Solution {
const int M = 1e9 + 7;
private:
    int solve(int n, int k, int target, vector<vector<int>>& dp) {
        if (n == 0 && target == 0) {
            return 1;
        }
        if (n == 0 || target <= 0) {
            return 0;
        }
        if (dp[n][target] != -1) {
            return dp[n][target]%M;
        }
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = (ans%M + solve(n-1, k, target - i, dp)%M)%M;
        }
        return dp[n][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        if (n*k < target) {
            return 0;
        }
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};


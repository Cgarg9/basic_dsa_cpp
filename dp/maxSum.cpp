// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {

private:
    int maxSumRecursive(vector<int>& nums, int i) {
        if (i >=  nums.size()) return 0;

        int take = nums[i] + maxSumRecursive(nums, i + 2);
        int notTake = maxSumRecursive(nums, i+1);
        
        return max(take, notTake);
    }

    int maxSumMemo(vector<int>& nums, int i, vector<int>& dp) {
        if (i >=  nums.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int take = nums[i] + maxSumMemo(nums, i + 2, dp);
        int notTake = maxSumMemo(nums, i+1, dp);
        
        return dp[i] = max(take, notTake);
    }

    int maxSumTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int take = 0, notTake = 0;
            if (i > 1) take = nums[i] + dp[i-2];
            notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }

    int maxSumOptimised(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0, prev2 = 0;
        for (int i = 0; i < n; i++) {
            int take = 0, notTake = 0;
            take = nums[i] + prev2;
            notTake = prev1;

            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    int maxSum(vector<int>& nums) {
        // return maxSumRecursive(nums, 0);

        // vector<int> dp(nums.size() + 1, -1);
        // return maxSumMemo(nums, 0, dp);

        // return maxSumTabulation(nums);

        return maxSumOptimised(nums);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.maxSum(nums) << endl;
    return 0;
}
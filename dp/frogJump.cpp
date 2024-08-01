// frog is at index 0 and needs to got to the last index
// can jump forward by 1 or 2 steps;
// energy spent is the difference of values at the two indices
// return min energy spent

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
private:
    int helpRecursive(int index, vector<int>& h) {
        if (index == 0) return 0;
        
        int oneStep = helpRecursive(index-1, h) + abs(h[index] - h[index-1]);
        int twoStep = INT_MAX;
        
        if (index > 1) twoStep = abs(h[index-2] - h[index]) + helpRecursive(index-2, h);

        return min(oneStep, twoStep);
    }

    int helpMemo(vector<int>& h, vector<int>& dp, int index) {
        if (index == 0) return 0;
        if (dp[index] != -1) return dp[index];

        int oneStep = helpMemo(h, dp, index-1) + abs(h[index] - h[index-1]);
        int twoStep = INT_MAX;
        
        if (index > 1) twoStep = abs(h[index-2] - h[index]) + helpMemo(h, dp, index-2);

        return dp[index] = min(oneStep, twoStep);
    }

    int helpTabulation(vector<int>& h) {
        vector<int> dp(h.size(), -1);
        dp[0] = 0;
        for (int i = 1; i < h.size(); i++) {
            int oneStep = dp[i-1] + abs(h[i] - h[i-1]);
            int twoStep = INT_MAX;
            if (i > 1) twoStep = dp[i-2] + abs(h[i-2] - h[i]);
            dp[i] = min(oneStep, twoStep);
        }
        return dp[h.size()-1];
    }

    int helpOptimised(vector<int>& h) {
        int prev = 0, prev2 = 0;
        for (int i = 1; i < h.size(); i++) {
            int oneStep = prev + abs(h[i] - h[i-1]);
            int twoStep = INT_MAX;
            if (i > 1) twoStep = prev2 + abs(h[i-2] - h[i]);
            int curr = min(oneStep, twoStep);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int minimumEnergy(vector<int>& height, int n) {
        // return helpRecursive(n-1, height);

        // vector<int> dp(n+1, -1);
        // return helpMemo(height, dp, n-1);

        // return helpTabulation(height);

        return helpOptimised(height);
    }
};

int main() {
    Solution obj;
    vector<int> height = {10, 20, 30, 10};
    int n = 4;
    cout << obj.minimumEnergy(height, n) << endl;
    return 0;
}
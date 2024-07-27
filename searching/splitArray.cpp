// https://leetcode.com/problems/split-array-largest-sum/description/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
private:
    bool check(int possibleSum, vector<int>& nums, int k) {
        int sum = 0;
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= possibleSum) {
                sum += nums[i];
            }
            else {
                count++;
                sum = nums[i];
            }
        }
        return count <= k ? true : false;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *(max_element(nums.begin(), nums.end()));
        if (k == nums.size()) return low;
        int high = 0;
        for (int i = 0; i < nums.size(); i++) high += nums[i];
        int ans = -1;
        while (low <= high) {
            int mid = (high - low)/2 + low;
            if (check(mid, nums, k)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

int main () {
    int k;
    cin >> k;
    vector<int> nums = {7,2,5,10,8};
    Solution obj;
    cout << obj.splitArray(nums, k) << endl;
    return 0;
}
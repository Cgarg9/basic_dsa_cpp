#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
    public:
        int lowerBound(vector<int>& nums, int k) {
            int low = 0; 
            int high = nums.size() - 1;
            int ans = -1;
            while (low <= high) {
                int mid = (high - low)/2 + low;
                if (nums[mid] == k) return nums[mid];
                else if (nums[mid] > k) high = mid - 1;
                else {
                    ans = nums[mid];
                    low = mid + 1;
                }
            }
            return ans;
        }
};

int main () {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.lowerBound(nums, k);
    return 0;
}
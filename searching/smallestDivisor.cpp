// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
private:
    bool check(int div, vector<int>& nums, int t) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int q = ceil(nums[i]/(double)div);
            sum += q;
        }
        return sum <= t ? true : false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *(max_element(nums.begin(), nums.end()));
        int ans = -1;
        while (low <= high) {
            int mid = (high-low)/2 + low;
            if (check(mid, nums, threshold)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << obj.smallestDivisor(nums, threshold);
    return 0;
}
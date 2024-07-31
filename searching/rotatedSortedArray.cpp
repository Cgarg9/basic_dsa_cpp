#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
    public:
        int rotatedSortedArray(vector<int>& nums, int target) {
            int low = 0, high = nums.size() - 1;
            while (low <= high) {
                int mid = (high-low)/2 + low;
                if (nums[mid] == target) return mid;
                // check for sorted half;
                // atleast one will be sorted

                // left sorted 
                else if (nums[mid] >= nums[low]) {
                    if (nums[mid] >= target && nums[low] <= target) high = mid - 1;
                    else low = mid + 1;
                }
                // right sorted
                else {
                    if (nums[mid] <= target && nums[high] >= target) low = mid + 1;
                    else high = mid - 1;
                }
            }
            return -1;
        }
};

int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int target;
    cin >> target;
    Solution obj;
    cout << obj.rotatedSortedArray(nums, target) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if (!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if (!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmallerElement(heights);
        vector<int> fwd = nextSmallerElement(heights);
        int maxi = -1;
        for (int i = 0; i < prev.size(); i++) {
            int height = heights[i];
            maxi = max(maxi, height*(fwd[i] - prev[i] - 1));
        }
        return maxi;
    }
};

int main () {
    Solution obj;
    vector<int> heights = {2,1,5,6,2,3};
    cout << obj.largestRectangleArea(heights);
    return 0;
}
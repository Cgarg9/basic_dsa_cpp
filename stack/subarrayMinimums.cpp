// Q: Find the sum of the minimum values from all the subarrays
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

vector<int> previousSmallerElement(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[i] <= nums[st.top()]) {
            st.pop();
        }
        if (!st.empty()) ans[i] = nums[st.top()];
        st.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int>& nums) {
    vector<int> ans(nums.size(), nums.size());
    stack<int> st;
    for (int i = nums.size()-1; i >= 0; i--) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            st.pop();
        }
        if (!st.empty()) ans[i] = nums[st.top()];
        st.push(i);
    }
    return ans;
}

int main() {
    int n; 
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> left = previousSmallerElement(nums);
    vector<int> right = nextSmallerElement(nums);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += ((i - left[i])*(right[i] - i)*nums[i]);
    }
    cout << sum << endl;
    return 0;
}
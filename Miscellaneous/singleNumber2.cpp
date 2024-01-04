// https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
// https://leetcode.com/problems/single-number-ii/

class Solution {
    private:
    void setBit(int a, vector<int>& v) {
        int i = 0;
        while (i < 32) {
            if (a & (1 << i)) {
                v[i] += 1;
                v[i] %= 3;
            }
            i++;
        }
    }
    int findNum(vector<int>& v) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (v[i] == 1) {
                ans |= (1<<i);
            }
        }
        return ans;
    }
    public:
    int singleElement(int arr[] ,int n) {
        vector<int> v(32, 0);
        for (int i = 0; i < n; i++) {
            setBit(arr[i], v);
        }
        int ans = findNum(v);
        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/aggressive-cows/0

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution {
private:
    bool check(int k, vector<int>& stall, int dist) {
        int cowPlaced = 1;
        int last = stall[0];
        for (int i = 1; i < stall.size(); i++) {
            if (stall[i] - last >= dist) {
                cowPlaced++;
                last = stall[i];
            }
            if (cowPlaced >= k) return true;
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n-1];
        int ans = -1;
        while (low <= high) {
            int mid = (high-low)/2 + low;
            if (check(k, stalls, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];
    Solution obj;
    cout << obj.solve(n, k, stalls);
    return 0;
}
// given an array of 0 and 1 and a number k 
// find the maximum length of consecutive 1s where you can flip at max k 0s.

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

int bruteForce(vector<int> v, int k) {
    int maxLength = 0;
    for (int i = 0; i < v.size(); i++) {
        int zeroes  = 0;
        for (int j = i; j < v.size(); j++) {
            if (v[j] == 0) zeroes++;

            if (zeroes <= k) maxLength = max(maxLength, j - i + 1);
            else break;
        }
    }
    return maxLength;
}

int SlidingWindow(vector<int> v, int k) {
    int maxLength = 0;
    int l = 0, r = 0, zeroes = 0;
    while (r < v.size()) {
        if (v[r] == 0) zeroes++;
        while (zeroes > k) {
            if (v[l] == 0) zeroes--;
            l++;
        }
        if (zeroes <= k) maxLength = max(maxLength,r-l+1);
        r++;
    }
    return maxLength;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = SlidingWindow(v, k);
    cout << ans << endl;
    return 0;
}
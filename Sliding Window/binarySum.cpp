// given an array consisting of 0 and 1 and given a total sum
// find the number of subarrays with the given sum
// solved using sliding window algorithm with difference of two function calls

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

int subarray(vector<int> v, int k) {
    if (k < 0) return 0;
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < v.size()) {
        sum += v[r];
        while (sum > k) {
            sum -= v[l];
            l++;
        }
        if (sum <= k) count += r -l + 1;
        r++;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << subarray(v, k) - subarray(v, k-1);
    return 0;
}
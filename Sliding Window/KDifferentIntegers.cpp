// given an array and a number k, find the number of subarrays with K distinct elements.
// to find this - find number of subarrays with atmost K distinct elements and with atmost (K-1) distinct elements

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

int subarrays(vector<int> v, int k)
{
    int l = 0, r = 0, count = 0;
    unordered_map<int, int> mp;
    while (r < v.size())
    {
        mp[v[r]]++;
        while (mp.size() > k)
        {
            mp[v[l]]--;
            if (mp[v[l]] == 0)
                mp.erase(v[l]);
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << subarrays(v, k) - subarrays(v, k - 1);
    return 0;
}
// Longest substring with atmost K distinct characters

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

int longestSubstring(string s, int k)
{
    // TC : O(N + N)
    // SC : O(const)
    int maxlength = 0, l = 0, r = 0;
    unordered_map<char, int> mp;

    while (r < s.length())
    {
        mp[s[r]]++;
        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
        }
        if (mp.size() <= k)
        {
            maxlength = max(maxlength, r - l + 1);
        }
        r++;
    }

    return maxlength;
}

int longestSubstringOptimised(string s, int k)
{
    // TC : O(N)
    // SC : O(const)
    int maxlength = 0, l = 0, r = 0;
    unordered_map<char, int> mp;

    while (r < s.length())
    {
        mp[s[r]]++;
        if (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        if (mp.size() <= k)
        {
            maxlength = max(maxlength, r - l + 1);
        }
        r++;
    }

    return maxlength;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << longestSubstringOptimised(s, k);
    return 0;
}
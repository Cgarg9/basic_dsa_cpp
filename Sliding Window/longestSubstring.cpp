// find longest substring without repeating characters

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

int main() {
    string s;
    cin >> s;
    unordered_set<char> st;
    int l = 0, r = 0;
    int maxi = -1;
    while (r < s.length()) {
        if (st.find(s[r]) != st.end()) {
            while (l <= r && st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }
        }
        st.insert(s[r]);
        r++;
        maxi = max(maxi, r - l);
    }
    cout << maxi << endl;
    return 0;
}
// remove K digits from the number so that the new number is the smallest possible.

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution
{
public:
    string removeKdigits(string S, int K)
    {
        if (K == S.length())
            return "0";
        stack<char> st;
        for (int i = 0; i < S.length(); i++)
        {
            while (!st.empty() && (S[i] - '0') < (st.top() - '0') && K > 0)
            {
                st.pop();
                K--;
            }
            st.push(S[i]);
        }
        while (!st.empty() && K > 0)
        {
            st.pop();
            K--;
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        // Remove leading zeros
        while (!ans.empty() && ans.back() == '0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        // If the result is empty, return "0"
        if (ans.empty())
            return "0";
        return ans;
    }
};

int main()
{
    Solution obj;
    string digits = "149811";
    int K = 3;
    cout << obj.removeKdigits(digits, K) << endl;
    return 0;
}
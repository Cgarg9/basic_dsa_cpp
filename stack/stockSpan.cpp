// The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days
// just before the given day, for which the price of the stock on the given day is less than or equal to its price
// on the current day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85},
// then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;
// used previous greater element
class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int> &price, int n)
    {
        stack<int> st;
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && price[st.top()] <= price[i])
            {
                st.pop();
            }
            if (!st.empty())
                ans[i] = i - st.top();
            else
                ans[i] = i + 1;
            st.push(i);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> ans = obj.calculateSpan(nums, n);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
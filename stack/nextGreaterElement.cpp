#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define ll long long int
void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}
int main()
{
    vector<int> test = {5, -2, -1, 8, 10};
    int n = test.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && test[st.top()] < test[i])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    print(nge);
    return 0;
}

// Given and array and a number k. Find the maximum sum.
//  You can either pick cards continuously from left end, right end or both till total cards is less than k
//  [6 2 3 4 7 2 1 7 1]
//  (6, 2, 7, 1) is a valid combination

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

int main()
{
    int k, n;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int leftSum = 0, rightSum = 0;
    int r = n - 1, l = 0;
    int maxi = -1;

    // sum of first window
    while (l < k)
    {
        leftSum += nums[l];
        l++;
    }
    l--;
    maxi = max(maxi, leftSum + rightSum);

    // now reduce l and increase from right
    while (l >= 0)
    {
        leftSum -= nums[l];
        l--;
        rightSum += nums[r];
        r--;
        maxi = max(maxi, leftSum + rightSum);
    }
    cout << maxi << endl;
    return 0;
}
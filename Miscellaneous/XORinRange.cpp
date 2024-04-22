#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;
// Given a range (l,R) find the XOR of all the numbers in this range.
// also find the XOR of all the number from (1, n)

int findXOR(int n)
{
    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    return n;
}
int main()
{
    // for 1 - n use this
    int l, r;
    cin >> l >> r;
    int XorR = findXOR(r);
    int XorL = findXOR(l - 1);
    int ans = XorL ^ XorR;
    cout << ans;
    return 0;
}
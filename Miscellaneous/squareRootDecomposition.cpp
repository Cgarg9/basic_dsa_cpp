
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int len = sqrt(n) + 1;
    vector<int> updatedVector(len, 0);
    for (int i = 0; i < n; i++)
    {
        updatedVector[i / len] += v[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int sum = 0;
        for (int i = l; i <= r;)
        {
            if ((i % len == 0) && (i + len - 1 <= r))
            {
                sum += updatedVector[i / len];
                i += len;
                // cout << sum << " ";
            }
            else
            {
                sum += v[i];
                i++;
                // cout << sum << " ";
            }
        }
        cout << sum << endl;
    }
    return 0;
}

// calculate prime factors using sieve

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

vector<int> findPrimeFactors(int N)
{
    vector<int> ans;
    vector<int> pf(N + 1, 1);
    // pf[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (pf[i] == 1)
        {   
            pf[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if (pf[j] == 1) pf[j] = i;
            }
        }
        // if (N % i == 0 && pf[i] == 1)
        //     ans.push_back(i);
    }
    // using the smallest prime factor
    while (N > 1) {
        ans.push_back(pf[N]);
        N /= pf[N];
    }
    return ans;
}

int main()
{
    vector<int> ans = findPrimeFactors(12246);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
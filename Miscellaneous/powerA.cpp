// Binary exponentiation
// T.C = O(N)
class Solution
{
public:
    // You need to complete this fucntion

    long long power(int N, int R)
    {
        long long int modulo = 1000000007;
        long long int ans = 1;
        long long int base = N;
        long long int e = R;
        while (e)
        {
            if (e & 1)
            {
                ans = (ans % modulo) * (base % modulo);
                ans %= modulo;
            }
            e >>= 1;
            base = ((base % modulo) * (base % modulo)) % modulo;
        }
        return ans;
    }
};

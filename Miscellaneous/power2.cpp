class Solution
{
public:
    bool isPowerofTwo(long long n)
    {
        bool condition1 = (n & (n - 1)) == 0;
        bool condition2 = n > 0;
        return condition1 && condition2;
    }
};

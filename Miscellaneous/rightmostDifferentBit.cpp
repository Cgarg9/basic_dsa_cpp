// https://www.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int x = m^n;
        int i = 0;
        while (i < 32) {
            if (x & (1<<i)) {
                return i + 1;
            }
            i++;
        }
        return -1;
    }
};

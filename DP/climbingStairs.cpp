// Application of Fibanacci Series

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int step1 = 2, step2 = 1, ans = 0;
        for (int i = 3; i <= n; i++)
        {
            ans = step1 + step2;
            step2 = step1;
            step1 = ans;
        }
        return ans;
    }
};
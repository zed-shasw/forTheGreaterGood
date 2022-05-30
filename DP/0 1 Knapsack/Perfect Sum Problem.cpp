// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

class Solution
{

public:
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int ind = j - arr[i - 1];
                if (j == 0)
                    dp[i][j] = 1;
                if (ind >= 0)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][ind];
                else
                    dp[i][j] = dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
        return dp[n][sum];
    }
};
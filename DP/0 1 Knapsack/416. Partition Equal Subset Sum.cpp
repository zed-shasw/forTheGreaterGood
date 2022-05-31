// Application of Subset Sum

class Solution
{
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int ind = j - arr[i - 1];
                if (j == 0)
                    dp[i][j] = 1;
                if (ind >= 0)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][ind];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return 0;
        return isSubsetSum(nums, sum / 2);
    }
};
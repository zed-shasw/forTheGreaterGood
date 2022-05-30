// Application of Subset Sum

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                int ind = j - arr[i - 1]; // check if it is possible to consider the element.
                if (ind >= 0)
                {
                    if (ind == 0 || dp[i - 1][ind]) // if adding element makes sense
                        dp[i][j] = 1 + dp[i - 1][ind];
                    else // else insert the value from last row
                        dp[i][j] = dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum] > 0;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return 0;
        return isSubsetSum(nums, sum / 2);
    }
};
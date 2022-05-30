int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            int ind = j - wt[i - 1];
            if (ind < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][ind] + val[i - 1], dp[i - 1][j]);
        }
    }
    return dp[n][W];
}
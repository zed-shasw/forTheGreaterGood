class Solution
{

public:
    int isSubsetSum(vector<int> arr, int sum)
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
        int flag = 0;
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[n][i])
            {
                flag = i;
                break;
            }
        }
        int ans = sum - (2 * flag);
        return ans;
    }

    int minDifference(int arr[], int n)
    {
        // Your code goes here
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = arr[i];
        int sum = accumulate(v.begin(), v.end(), 0);
        int ans = isSubsetSum(v, sum);
        return ans;
    }
};
